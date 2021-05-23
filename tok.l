%{
#include "calc.tab.h"
#include "calc.h"
#include<stdlib.h>
#include <string.h>
#include<stdio.h>


int Adr=0;//counter for global symbol tanble
int* current_addr=&Adr; //pointer to the counter of a symbol table, it will help us to switch between different symbol tables


symrec *sym_table = (symrec *)0; // Global symbol table
symrec **current_sym_table=&sym_table; // pointer that points to the current sybol table  at  use.



%}
number [0-9]+
id [a-z]+
%%
[ ] {}
";" {printf("%s\n",yytext);return SEMIC;}
"/*".*"*/" {}
"input" {printf("%s\n",yytext);return INPUT;}
"output" {printf("%s\n",yytext);return OUTPUT;}
"for" {printf("%s\n",yytext);return FOR;}
"while" {printf("%s\n",yytext);return WHILE;}
"length" {printf("%s\n",yytext);return LENGTH;}
"if" {printf("%s\n",yytext);return IF;}
"else" {printf("%s\n",yytext);return ELSE;}
"break" {printf("%s\n",yytext);return BREAK;}
"continue" {printf("%s\n",yytext);return CONTINUE;}

"<"   {printf("%s\n",yytext);return LT;}
">"   {printf("%s\n",yytext);return GT;}
"end" {printf("in END\n"); 
      (*current_sym_table)=(symrec *)sym_table;
    current_addr=&Adr;
      
    return END;
      }
"return" {  return RETURN;}

"decl" {

return DECL;

} 
"str "{id} {

  //Regular expression for string input

  char name[strlen(yytext)-2];
  memset(name, '\0', sizeof(name));
  strncpy(name,yytext+4,strlen(yytext)-4); //storing the name for the string var in "name"
  symrec *s;
  s=getsym(name,current_sym_table);  //checking if this id already exists in the symbol table
  
  if(s==0){
    s=putsym(name,"string",current_sym_table,current_addr);yylval.tptr=s; //if not, insert it into symbol table 
   
  } else{
    printf("fun name already use\n");
    // return 0;
  }
 
  return VAR;
  } 

\".*\" {sscanf(yytext,"%s",yylval.string);printf("%s\n",yytext);return STR;}
{number} {sscanf(yytext,"%d",&yylval.val);printf("%s\n",yytext);return NUM;}

{id} {symrec *s;s=getsym(yytext,current_sym_table); if(s==0) s=putsym(yytext,"identifier",current_sym_table,current_addr);yylval.tptr=s;  return VAR;}

"def "{id} {
    

  char name[strlen(yytext)-2];
  memset(name, '\0', sizeof(name));
  strncpy(name,yytext+4,strlen(yytext)-4);
  
  //storing the function name into "name"
  symrec *s;s=getsym(name,current_sym_table); //checking if the function already exists  in the symbol table or not
  
  if(s==0){
    //if  not, we insert that function into the symbol table
    s=putsym(name,"function",current_sym_table,current_addr);yylval.tptr=s;
    
  } else{
    printf("fun name already use\n");
    
  }
  sym_table = *current_sym_table; 
  current_sym_table=&(s->sym_func);//updating the current_sym_tab to point to this functions symbol table
  
  s->sym_addr=0; 
  
  

  current_addr=&(s->sym_addr); // updating the current_addr to point to  the symbol table counter specific to this table
  
  
  return FUNC;
  } 

"call "{id} {


  
  char name[strlen(yytext)-3];
  memset(name, '\0', sizeof(name));
  strncpy(name,yytext+4,strlen(yytext)-4);
  
  sscanf(name,"%s",&yylval.fun_name);
  return FUNC_CALL;
}


\n|.  {return yytext[0];}
%%



symrec * putsym (char *sym_name,char* sym_type,symrec **current_sym_tab,int* current_addr){
  symrec *curr_table = (*current_sym_tab) ;
  
  symrec *ptr= (symrec *) malloc (sizeof (symrec));//initialising a new ptr
  
  ptr->name = (char *) malloc (strlen (sym_name) + 1); 
  
  strcpy (ptr->name,sym_name);//assigning the name 
  
  sprintf(ptr->addr,"%d",*current_addr); //The address of the current node in the symbol table
  
  (*current_addr)+=4;
  
  // Adr=Adr+4;
  ptr->next = (struct symrec *)curr_table;
  
  ptr->type=sym_type;
  
  
  if(strcmp(sym_type,"function")==0){
    
    ptr->sym_func= (symrec *)0;;
  }
  
  
  
  (*current_sym_tab) = ptr;
  
  return ptr;
}

symrec *getsym (char *sym_name, symrec **current_sym_tab){
  symrec *ptr=(symrec *)(*current_sym_tab);

  while(ptr!=NULL){

    if(!ptr->name){ //check if name is NULL,this covers boundary conditions when the symbol table has zero nodes
      
      return 0;
    }
    if (strcmp (ptr->name,sym_name) == 0){
           //check if the identifier already exists in the table
           return ptr;}
    ptr = (symrec *)ptr->next;
  }


  return 0;
}

int yywrap() 
 { 
  return 1; 
 } 



  
