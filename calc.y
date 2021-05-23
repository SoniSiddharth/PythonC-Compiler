// including libraries and data structures
%{
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>  
	#include "calc.h"  /* Contains definition of `symrec'*/
	int  yylex(void);
	void yyerror (char  *);

	// variables to define different states which statements are executing or flags
	int whileStart=0,nextJump=0,forStart=0,nextJumpfor=0,ifelseStart=0,nextJumpIfElse=0;
	int count=0;
	int lenfunc=0;
	int labelCount=0;
	int inForloop=0;     
	int inWhileloop=0;
	int msg_flag=0;
	FILE *fp;
	struct StmtsNode *final;
	void StmtsTrav(stmtsptr ptr);
	void StmtTrav(stmtptr ptr);
%}

// returning datatypes yyval structure
%union {
	int   val;  /* For returning numbers.                   */
	struct symrec  *tptr;   /* For returning symbol-table pointers      */
	char fun_name[1000]; // character array for function name
	char c[1000];		
	char nData[100];
	char string[1000];
	// statements as nodes of parse tree 
	struct StmtNode *stmtptr;
	struct StmtsNode *stmtsptr;
}

// defining tokens
%token  <val> NUM 
%token <val> 
%token <string> STR
%token  WHILE FOR SEMIC IF ELSE BREAK CONTINUE END RETURN INPUT OUTPUT LENGTH  
%token  <c> DECL GT LT 
%token <tptr> VAR FUNC 
%token <fun_name>  FUNC_CALL
%type  <c>  exp RELOP 
%type <nData> x 
%type <stmtsptr> stmts 
%type <stmtptr> stmt a_stat

%right '='
%left '-' '+'
%left '*' '/'


/* Grammar follows */

%%
prog: stmts {final=$1;}
stmts: stmt {	
					$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode)); // for multiple  statements
	 				$$->singl=1;$$->left=$1,$$->right=NULL;}
			|stmt stmts {
					$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
					$$->singl=0;$$->left=$1,$$->right=$2;}
 			;

// grammar for function definition with exactly 2 parameters
stmt:
			'\n' {$$=NULL;}
			|FUNC '(' VAR ',' VAR')' '{' stmts '}''\n' END '\n' {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					sprintf($$->initCode,"jal m_%s\n.data\n%s : .space %d \n.text\nFunc_%s:\n subu $sp,$sp,4 \n sw $ra,($sp)\n\nla $t8,%s\nlw $t0, %s($t8)\nlw $t1, %s($t8)\n",$1->name,$1->name,5000,$1->name,$1->name,$3->addr,$5->addr);
					$$->isFunDef=1;
					$$->isString=0; // these are to ensure we put the given code at correct block just to skip over from unnecessary if blocks
					$$->isFunCall=0;
					$$->isReturn=0;
					$$->isString=0;
					$$->isReturn=0;
					$$->isArray=0;
					$$->isArrayOne=0;
					$$->isArrayTwo=0;
					$$->isOutputOne=0;
					$$->isOutputTwo=0;
					$$->isInput=0;					
					$$->down=$8;
					$$->FuncName=$1->name;
					// current_sym_table = $2->sym_func;
					}

// grammar for returning from a function (returing a variable)
			| RETURN VAR {					
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isFunDef=0;
					$$->isFunCall=0;
					$$->isString=0;
					$$->isReturn=1;
					//storing the return value in $v0
					sprintf($$->returnCode,"lw $v0, %s($t8)\nmove $t8,$t7\n",$2->addr);
					}

// grammar for function call
			|VAR '=' FUNC_CALL '(' VAR ',' VAR ')' '\n' { 					
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					sprintf($$->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", $5->addr,$7->addr);
					// printf("\n\n%s\n",$3->type);
					$$->isFunDef=0;
					$$->isFunCall=1;
					$$->isString=0;
					$$->isReturn=0;
					$$->isArray=0;
					$$->isArrayOne=0;
					$$->isArrayTwo=0;
					$$->isOutputOne=0;
					$$->isOutputTwo=0;
					$$->isInput=0;		

					sprintf($$->insertAttr,"la $t8,%s\nsw $t0,0($t8)\nsw $t1,4($t8)\n",$3);
					sprintf($$->bodyCode,"jal Func_%s\n sw $v0,%s($t8)\n ",$3,$1->addr);
					}

// grammar for detecting errors direct calling function wothout using "call" keyword
			|VAR '=' VAR '(' VAR ',' VAR ')' '\n'{
					printf("\n\n%s\n",$3->type);
					if(strcmp("function",$3->type)==0){
						printf("\n**********\nSyntax Error!! missing \"call\" after \"=\"\n for function call\n*******\n");
						exit(0);
					}
					else{					
						printf("\n**********\nSyntax Error!! Function name %s is not defined\n*******\n",$3->name);
						exit(0);
					}
					}

// grammar for while loop
			| WHILE '(' VAR RELOP VAR ')' '{' stmts '}' '\n' {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isWhile=1;
					$$->isString=0;
					sprintf($$->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", $3->addr,$5->addr);
					sprintf($$->initJumpCode,"%s",$4);
					$$->down=$8; }

// grammar for IF and break condition 
			| IF '(' VAR RELOP VAR ')' BREAK '\n' {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isBreakorContinue = 1;
					$$->isString=0;
					sprintf($$->initCode,"lw $t3, %s($t8)\nlw $t4, %s($t8)\n", $5->addr,$3->addr);
					sprintf($$->initJumpCode,"%s",$4);
					}

// grammar for IF ELSE statements
			| IF '(' VAR RELOP VAR ')' '{' stmts '}' ELSE '{' stmts '}' '\n'{
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isIfElse = 1;
					$$->isString=0;
					sprintf($$->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", $3->addr,$5->addr);
					sprintf($$->initJumpCode,"%s",$4);
					$$->ifcode = $8;
					$$->elsecode = $12;
					}

// grammar for FOR loop
			| FOR '(' a_stat SEMIC VAR RELOP VAR SEMIC a_stat ')' '{' stmts '}' '\n' {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isFor=1;
					$$->isString=0;
					sprintf($$->initCode,"lw $t0, %s($t8)\nlw $t1, %s($t8)\n", $5->addr,$7->addr);
					sprintf($$->initJumpCode,"%s",$6);
					$$->down=$12; $$->forinit=$3; $$->forincre=$9; 
					}
			| a_stat {$$=$1;}


// Grammar for array declaration
			| DECL VAR '[' NUM ']'  {			
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isWhile=0;
					$$->isArray=1;
					$$->isString=0;
					$$->isArrayOne=0;
					$$->isArrayTwo=0;

					$$->isFunDef=0;
					$$->isFunCall=0;
					$$->isReturn=0;
					$$->isInput=0;
					$$->isOutput=0;      
					sprintf($$->bodyCode,".data\n%s : .space %d \n.text\n",$2->name,$4*4);
				}

// Error handling when the number of elements is a variable (not allowed)
			| DECL VAR '[' VAR ']''\n'{
					printf("\n**********\nSyntax Error!! invalid type in '['']', allowed format : decl %s[20]\n*******\n",$2->name);
					exit(0);          }

// assigning a value to an element of array in case of variableh
			| VAR '[' VAR ']' '=' exp '\n' {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isArray=0;
					$$->isArrayOne=1;
					$$->isArrayTwo=0;
					$$->isString=0;
					$$->isWhile=0;
					$$->isFunDef=0;
					$$->isFunCall=0;
					$$->isReturn=0;
					$$->isInput=0;
					$$->isOutput=0;	 
					sprintf($$->bodyCode,"%s\nmove $s1,$t0\nlw $t0,%s($t8)\nli $t3,4\nmul $t0,$t0,$t3\nsw $s1,%s($t0)\n",$6,$3->addr,$1->name);
					}

// when element is directly known assigning value 
			| VAR '[' NUM ']' '=' exp '\n' {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isArray=0;
					$$->isArrayOne=0;
					$$->isArrayTwo=1;
					$$->isString=0;
					$$->isWhile=0;$$->isArray=0;$$->isFunDef=0;$$->isFunCall=0;$$->isReturn=0;$$->isInput=0;$$->isOutput=0;
					$$->isString=0;
					$$->isReturn=0;
					$$->isInput=0;
					sprintf($$->bodyCode,"%s\nmove $s1,$t0\nlw $t0,%d($t8)\nli $t3,4\nmul $t0,$t0,$t3\nsw $s1,%s($t0)\n",$6,$3*4,$1->name);
					}

// gammar for input from the user
			| INPUT '(' VAR ')''\n'{					
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isFunDef=0;
					$$->isFunCall=0;
					$$->isReturn=0;
					$$->isInput=1;
					$$->isArray=0;
					$$->isArrayOne=0;
					$$->isArrayTwo=0;
					$$->isString=0;
					$$->isOutput=0;
					sprintf($$->bodyCode,"li $v0,5\nsyscall\nmove $t0,$v0\nsw $t0,%s($t8)\n",$3->addr);
					}

// output to the user with variable stored value
			| OUTPUT '(' VAR ')''\n'{					
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isString=0;
					$$->isFunDef=0;$$->isOutputOne=0;$$->isOutputTwo=0;$$->isFunCall=0;$$->isReturn=0;$$->isInput=0;$$->isOutput=1;$$->isArray=0;$$->isArrayOne=0;$$->isArrayTwo=0;
					// sprintf($$->initCode,".data\nmsg: .asciiz \"\\n\"\n");
					char* tp=$3->type;
					if(strcmp("string",tp)==0){
						sprintf($$->bodyCode,"li $v0,4\nla $a0,%s\nsyscall\n",$3->name);
					}
					else{
						sprintf($$->bodyCode,"lw $t0,%s($t8)\nli $v0,1\nmove $a0,$t0\nsyscall\n",$3->addr);
					}				 
				}

// output a number to the user
				| OUTPUT '(' NUM ')''\n'{
						$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
						$$->isString=0;
						$$->isFunDef=0;$$->isOutputOne=1;$$->isOutputTwo=0;$$->isFunCall=0;$$->isReturn=0;$$->isInput=0;$$->isOutput=0;$$->isArray=0;$$->isArrayOne=0;$$->isArrayTwo=0;
						// sprintf($$->initCode,".data\nmsg: .asciiz \"\\n\"\n");
						sprintf($$->bodyCode,"li $t0,%d\nli $v0,1\nmove $a0,$t0\nsyscall\n",$3);				 
						}

// output an element of an array
				| OUTPUT '(' VAR '['VAR']' ')''\n'{					
						$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
						$$->isString=0;$$->isFunDef=0;$$->isOutputOne=0;$$->isOutputTwo=1;$$->isFunCall=0;$$->isReturn=0;$$->isInput=0;$$->isOutput=0;$$->isArray=0;$$->isArrayOne=0;$$->isArrayTwo=0;
						// sprintf($$->initCode,".data\nmsg: .asciiz \"\\n\"\n");
						sprintf($$->bodyCode,"lw $t0,%s($t8)\nmove $t2,$t0\nli $t3,4\nmul $t2,$t2,$t3\nlw $t0,%s($t2)\nli $v0,1\nmove $a0,$t0\nsyscall\n",$5->addr,$3->name);			 
						}

// grammar for In-built function length of a string stored in a variable
				| VAR '=' LENGTH '(' VAR ')' '\n' {
						$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
						$$->isLength=1;
						sprintf($$->stringLen,"la $s0,%s\nlb $s1,($s0)\nli $t0,0\nsrchlp_%d: beq $s1, $zero, srchdn_%d \naddi $t0,$t0,1\naddi $s0,$s0,1\nlb $s1,($s0)\nb srchlp_%d\nsrchdn_%d: sw $t0,%s($t8)\n",$5->name,lenfunc,lenfunc,lenfunc,lenfunc,$1->addr);
						lenfunc++;
						}

// length of a string directly
				|	VAR '=' LENGTH '(' STR ')' '\n'{
					// char *s=$4;					
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isLength=1;
					int l=strlen($5)-2;
					sprintf($$->stringLen,"li $t0,%d\nsw $t0,%s($t8)\n",l,$1->addr);
					}	 
				;

// greater than and less than operators
RELOP : GT	{sprintf($$,"ble $t0,$t1,");}
			| LT{sprintf($$,"bge $t0,$t1,");}
// | LTE {sprintf($$,"bge $t0,$t1,");}
// | GTE{sprintf($$,"ble $t0,$t1,");}
			;

// expressions and definitions
a_stat: VAR '=' exp    {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					$$->isWhile = 0 ; $$->isFor=0;$$->isString=0;
					sprintf($$->bodyCode,"%s\nsw $t0,%s($t8)\n", $3, $1->addr);
					$$->down=NULL; }

			| VAR '=' STR  {
					$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
					char* tp=$1->type;
					if(strcmp("string",tp)==0){
					$$->isString=1;
					sprintf($$->stringCode,".data\n%s: .asciiz %s\n.text\n",$1->name,$3);}
					}
			| error '\n' { yyerrok; }
			;

// array definition and other expressions with operators
exp: VAR '[' x ']' {
					sprintf($$,"%s\nli $t3,4\nmul $t0,$t0,$t3\nlw $t0,%s($t0)\n",$3,$1->name);}
				
			|  x             { sprintf($$,"%s",$1);count=(count+1)%2;}
			| x '+' x  		 { sprintf($$,"%s\n%s\nadd $t0, $t0, $t1",$1,$3);}
			| x '-' x        { sprintf($$,"%s\n%s\nsub $t0, $t0, $t1",$1,$3);}
			| x '*' x        { sprintf($$,"%s\n%s\nmul $t0, $t0, $t1",$1,$3);}
			| x '/' x        { sprintf($$,"%s\n%s\ndiv $t0, $t0, $t1",$1,$3);}
			;

x:   		NUM {sprintf($$,"li $t%d, %d",count,$1);count=(count+1)%2; }
			| VAR {sprintf($$, "lw $t%d, %s($t8)",count,$1->addr);count=(count+1)%2; }
			;


%%
// code for parse tree traversal
void StmtsTrav(stmtsptr ptr){
	if(ptr==NULL) return;
	if(ptr->singl==1){
		StmtTrav(ptr->left);
	}
	else{
		StmtTrav(ptr->left);
		StmtsTrav(ptr->right);
	}
}

void StmtTrav(stmtptr ptr){
	int ws,nj;
	 
	if(ptr==NULL) return;
	if(ptr->isString==1 && ptr->isWhile==0 
		&&ptr->isFor==0 && ptr->isIfElse==0 
		&&ptr->isBreakorContinue==0 && ptr->isFunCall==0 
		&& ptr->isFunDef==0 && ptr->isArray==0 
		&& ptr->isInput==0 && ptr->isOutput==0
		&&ptr->isOutputOne==0&&ptr->isOutputTwo==0
		&&ptr->isArrayOne==0 && ptr->isArrayTwo==0){
			fprintf(fp,"%s",ptr->stringCode);
	}
	if(ptr->isWhile==0 &&ptr->isFor==0 
		&& ptr->isIfElse==0 &&ptr->isBreakorContinue==0 
		&& ptr->isFunCall==0 && ptr->isFunDef==0 
		&& ptr->isArray==0 && ptr->isInput==0 
		&& ptr->isOutput==0&&ptr->isOutputOne==0
		&&ptr->isOutputTwo==0&&ptr->isArrayOne==0 
		&& ptr->isArrayTwo==0 ){
			fprintf(fp,"%s\n",ptr->bodyCode);
	}
	
	if(ptr->isOutputOne==0 && ptr->isOutputTwo==0 
		&& ptr->isArray==1 && ptr->isArrayOne==0 
		&& ptr->isArrayTwo==0  && ptr->isWhile==0 
		&& ptr->isReturn==0&& ptr->isFunCall==0 
		&& ptr->isFunDef==0 && ptr->isInput==0 
		&& ptr->isOutput==0) {
			fprintf(fp,"%s\n",ptr->bodyCode);
	}

	if(ptr->isArray==0&&ptr->isArrayOne==1 
		&& ptr->isArrayTwo==0  && ptr->isWhile==0 
		&& ptr->isReturn==0&& ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isInput==0 
        && ptr->isOutput==0) {
            printf("inside the is array");
            fprintf(fp,"%s\n",ptr->bodyCode);
    }
	
    if(ptr->isArray==0 && ptr->isArrayOne==0 
        && ptr->isArrayTwo==1 && ptr->isWhile==0 
        && ptr->isReturn==0 && ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isInput==0 
        && ptr->isOutput==0) {
            printf("inside the is array");
            fprintf(fp,"%s\n",ptr->bodyCode);
    }
	

    if(ptr->isLength==1 && ptr->isWhile==0 
        &&ptr->isFor==0 && ptr->isIfElse==0 
        &&ptr->isBreakorContinue==0 && ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0
        &&ptr->isOutputOne==0&&ptr->isOutputTwo==0
        &&ptr->isArrayOne==0 && ptr->isArrayTwo==0){
            fprintf(fp,"%s",ptr->stringLen);
    }

    if(ptr->isFunDef==1 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0 
        && ptr->isWhile==0 &&ptr->isFor==0 
        && ptr->isIfElse==0 &&ptr->isBreakorContinue==0 
        && ptr->isFunCall==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0
        &&ptr->isOutputOne==0&&ptr->isOutputTwo==0
        &&ptr->isArrayOne==0 && ptr->isArrayTwo==0){
            fprintf(fp,"%s\n",ptr->initCode);
            StmtsTrav(ptr->down);
            fprintf(fp,"lw $ra,($sp)\n addu $sp,$sp,4\n jr $ra\nm_%s:\n",ptr->FuncName);
	 }

    if(ptr->isFunCall==1 && ptr->isFunDef==0 
        && ptr->isReturn==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0){
            fprintf(fp,"%s\n%s\n%s\n",ptr->initCode,ptr->insertAttr,ptr->bodyCode);
    }
	 
    if(ptr->isReturn==1&& ptr->isFunCall==0 
        && ptr->isFunDef==0 && ptr->isArray==0 
        && ptr->isInput==0 && ptr->isOutput==0){
        fprintf(fp,"%s\n",ptr->returnCode);
    }
		 
    if(ptr->isInput==1 && ptr->isFunDef==0 
        && ptr->isFunCall==0 && ptr->isReturn==0 
        && ptr->isOutput==0 && ptr->isArray==0){
            fprintf(fp,"%s\n",ptr->bodyCode);
    }
	
    if(ptr->isOutput==1 &&ptr->isOutputOne==0
        &&ptr->isOutputTwo==0&& ptr->isInput==0 
        && ptr->isFunDef==0 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0){
        if(msg_flag==0){
            fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n.text\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
            msg_flag=1;
        }
		else{
            fprintf(fp,"%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
        }		
    }
    if(ptr->isOutput==0 &&ptr->isOutputOne==1
        &&ptr->isOutputTwo==0&& ptr->isInput==0 
        && ptr->isFunDef==0 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0){
        if(msg_flag==0){
            fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n.text\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);		
            msg_flag=1;
        }
        else{
            fprintf(fp,"%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
        }		
    }

    if(ptr->isOutput==0 &&ptr->isOutputOne==0
        &&ptr->isOutputTwo==1&& ptr->isInput==0 
        && ptr->isFunDef==0 && ptr->isFunCall==0 
        && ptr->isReturn==0 && ptr->isArray==0){
    		if(msg_flag==0){
			//  fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
                fprintf(fp,".data\nmsg: .asciiz \"\\n\"\n\n.text\n%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
                msg_flag=1;
            }
            else{
            fprintf(fp,"%s\nli $v0,4\nla $a0,msg\nsyscall\n",ptr->bodyCode);
        }
		
    }
	
	 
	if(ptr->isIfElse==1){ws=ifelseStart; ifelseStart++;nj=nextJumpIfElse;nextJumpIfElse++;
		fprintf(fp,"IfStart%d:%s\n%s CheckpointIfElse%d\n",ws,ptr->initCode,ptr->initJumpCode,nj);StmtsTrav(ptr->ifcode);
		fprintf(fp,"j ElseEnd%d\nCheckpointIfElse%d:\n",ws,nj);
		StmtsTrav(ptr->elsecode);
		fprintf(fp,"ElseEnd%d:\n",ws);
	}

	if(ptr->isWhile==1){ws=whileStart; whileStart++;nj=nextJump;nextJump++;inWhileloop=1;
		fprintf(fp,"WhileStart%d:%s\n%s CheckpointWhile%d\n",ws,ptr->initCode,ptr->initJumpCode,nj);StmtsTrav(ptr->down);
		fprintf(fp,"j WhileStart%d\nCheckpointWhile%d:\n",ws,nj); 
		inWhileloop=0;
	}
	
	if(ptr->isFor==1){ws=forStart; forStart++;nj=nextJumpfor;nextJumpfor++;inForloop=1;
		StmtTrav(ptr->forinit);
		fprintf(fp,"ForStart%d:%s\n%s CheckpointFor%d\n",ws,ptr->initCode,ptr->initJumpCode,nj);StmtsTrav(ptr->down);
		StmtTrav(ptr->forincre);
		fprintf(fp,"j ForStart%d\nCheckpointFor%d:\n",ws,nj);
		inForloop=0;
	}
		
	if(ptr->isBreakorContinue==1){			
		if(inForloop==1 && inWhileloop==0){
			printf("inForloop\n");
			ws = forStart;
			ws--;
			fprintf(fp,"%s\n%s CheckpointFor%d\n",ptr->initCode,ptr->initJumpCode,ws);
		}
		if(inWhileloop==1 && inForloop==0){
			printf("inWhileloop\n");
			ws = whileStart;
			ws--;
			fprintf(fp,"%s\n%s CheckpointWhile%d\n",ptr->initCode,ptr-> initJumpCode,ws);
		}
	}

}
	 


int main (int argc, char **argv)
{	
	char temp[100];
    strcpy(temp,argv[1]);

    // printf("temp: %s\n",temp);
    int l = strlen(argv[1]);
    // printf("length : %d\n", l);
    char check_str[100];
    for(int i=0; i<l; i++){
        if (i>15){
            check_str[i-16] = temp[i];
        }
    }
    check_str[l-16] = '\0';
    // printf("check_str : %s\n", check_str);
    // printf("argc : %d\n", argc);
    if (strcmp(check_str, "factorial.prog")==0){
        fp=fopen("./assemblyCodes/factorial.asm","w");
		printf("Factorial Done\n");
    }
	else if (strcmp(check_str, "arraysum.prog")==0){
		fp=fopen("./assemblyCodes/arraysum.asm","w");
		printf("Array summation Done\n");
	}
	else if (strcmp(check_str, "basicio.prog")==0){
		fp=fopen("./assemblyCodes/basicio.asm","w");
		printf("Basic Input Output Done\n");
	}
	else if (strcmp(check_str, "errorfunc.prog")==0){
		fp=fopen("./assemblyCodes/errorfunc.asm","w");
		printf("Error Checking Done\n");
	}
	else if (strcmp(check_str, "fibonacci.prog")==0){
		fp=fopen("./assemblyCodes/fibonacci.asm","w");
		printf("Fibonacci Done\n");
	}
	else if (strcmp(check_str, "nestedFor.prog")==0){
		fp=fopen("./assemblyCodes/nestedFor.asm","w");
		printf("Nested For loop check Done\n");
	}
	else if (strcmp(check_str, "relop.prog")==0){
		fp=fopen("./assemblyCodes/relop.asm","w");
		printf("Relational Operators check Done\n");
	}
	else if (strcmp(check_str, "simpleFunction.prog")==0){
		fp=fopen("./assemblyCodes/simpleFunction.asm","w");
		printf("Simple Function check Done\n");
	}
	else if (strcmp(check_str, "stringlen.prog")==0){
		fp=fopen("./assemblyCodes/stringlen.asm","w");
		printf("String length calculation Done\n");
	}
	else if (strcmp(check_str, "whilefor.prog")==0){
		fp=fopen("./assemblyCodes/whilefor.asm","w");
		printf("For inside while loop check Done\n");
	}

	fprintf(fp,".data\nmain: .space 10000\n.text\nla $t8,main\nla $t7,main\n");
	yyparse ();
	StmtsTrav(final);
	fclose(fp);
}

void yyerror (char *s)  /* Called by yyparse on error */
{
	printf ("%s\n", s);
}
