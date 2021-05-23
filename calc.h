#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

struct symrec
{
  char *name;         //name of the identifier(VAR,array,string) as well as the function name 
  char addr[100];      //the position of the node in its symbol table
  struct symrec *next;  //pointer to the next node

  char *type;  //stores the type of identifier ("identifier","string" or "function")
  int sym_addr;
  struct symrec *sym_func; // if the identifier is a function then this will be the  Symbol table
};

typedef struct symrec symrec;


extern symrec *sym_table;

symrec *putsym();
symrec *getsym();

typedef struct StmtsNode *stmtsptr;
typedef struct StmtNode *stmtptr;

//Structure of a set of statements
struct StmtsNode
{
  int singl;
  struct StmtNode *left;
  struct StmtsNode *right;
};


//Structure of a single statement
struct StmtNode
{
  //below defined integers are a set of flags used for generating the parse tree
  int isString;
  int isWhile; 
  int isFor;
  int isIfElse;
  int isBreakorContinue;
  int isFunCall;
  int isFunDef;
  int isReturn;
  int isArray;
  int isArrayOne;
  int isArrayTwo;
  int isOutputOne;
  int isOutputTwo;
  int isOutputThree;
  int isLength;
  int isInput;
  int isOutput;
  char *FuncName;

  //Below are the bufferes to store the assembly code corresponding to a procedure 
  char initCode[100];
  char initJumpCode[20];
  char bodyCode[1000];
  char returnCode[100];
  char insertAttr[100];
  char stringCode[100];
  char stringLen[100];
  struct symrec * funcAdd;
  struct StmtsNode *down;
  struct StmtsNode *ifcode;
  struct StmtsNode *elsecode;
  struct StmtNode *forinit;
  struct StmtNode *forincre;
};


