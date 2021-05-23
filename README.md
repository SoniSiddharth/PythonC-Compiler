# Compiler for Miniature Version Python ⭐

## Instructions to Run :runner:

```make help```<br>
```make```<br>
```make fibonacci```<br>
```make factorial```<br>
```make whilefor```<br>
```make basicio```<br>
```make errorfunc```<br>
```make relop```<br>
```make arraysum```<br>
```make simplefunction```<br>
```make stringlen```<br>

## Directory Structure 📁

```
├─── a.out
├─── calc.h
├─── calc.tab.c
├─── calc.tab.h
├─── calc.y
├─── lex.yy.c
├─── Makefile
├─── README.md
├─── Readme.txt
├─── tok.l
│
├─── assemblyCodes
│    ├─── arraysum.asm
│    ├─── asmb.asm
│    ├─── basicio.asm
│    ├─── errorfunc.asm
│    ├─── factorial.asm
│    ├─── fibonacci.asm
│    ├─── relop.asm
│    ├─── simpleFunction.asm
│    ├─── stringlen.asm
│    └─── whilefor.asm
│
└─── testprograms
     ├─── arraysum.prog
     ├─── basicio.prog
     ├─── errorfunc.prog
     ├─── factorial.prog
     ├─── fibonacci.prog
     ├─── nestedFor.prog
     ├─── relop.prog
     ├─── simpleFunction.prog
     ├─── stringlen.prog
     ├─── test_ppt.prog
     └─── whilefor.prog
```

## Lexer patterns :fire:

| Regex Variable | Regex |
| :---: | :---: |
| DIGIT | [0-9]+ | 
| IDENTIFIER/VAR | [a-zA-Z_]+ | 
| FUNCTION_CALL |"call " {IDENTIFIER}|
| FUNCTION_DEF |"def " {IDENTIFIER}|
| array_DECL |"decl " {IDENTIFIER}|
| STRING_REGEX | "\\""(.)*"\\"" | 
|  SEMIC          |";"       |        
|  COMMENT        |"/*".*"*/"|         
|  INPUT_VALUE    |"input"   |        
|  PRINT          |"output"  |         
|  FOR_LOOP       |"for"     |         
|  WHILE_LOOP     |"while"   |        
|  LENGTH         |"length"  | 
|  IF             |"if"      |
|  ELSE           |"else"    |     
|  BREAK          |"break"   |      
|  CONTINUE       |"continue"|            


## Grammar :fire:

```
prog: stmts (This is the root statement)
```
```
stmts: stmt
```
```
stmt:|FUNC '(' VAR ',' VAR')' '{' stmts '}''\n' END '\n' (Function definition)

     | RETURN VAR (Fuction return )

     |VAR '=' FUNC_CALL '(' VAR ',' VAR ')' '\n' (Function call)
  
     | WHILE '(' VAR RELOP VAR ')' '{' stmts '}' '\n' (While loop)

     | IF '(' VAR RELOP VAR ')' BREAK '\n' (If for the break purpose)
     
     | IF '(' VAR RELOP VAR ')' '{' stmts '}' ELSE '{' stmts '}' '\n' (if else statement)
     
     | FOR '(' a_stat SEMIC VAR RELOP VAR SEMIC a_stat ')' '{' stmts '}' '\n' (for loop)
     
     | DECL VAR '[' NUM ']' '\n' (Array declairation of constant size)
     
     | DECL VAR '[' VAR ']''\n'  (array declairation)

     | VAR '[' VAR ']' '=' exp '\n' (array value assigning)

     | VAR '[' NUM ']' '=' exp '\n' (array value assigning for a specific number)

     | INPUT '(' VAR ')''\n' (Taking input in a variable)

     | OUTPUT '(' VAR ')''\n' (printing  variable)

     | OUTPUT '(' NUM ')''\n' (printing a number)

     | VAR '=' LENGTH '(' VAR ')' '\n' (Length calcuation)

     | VAR '=' LENGTH '(' STR ')' '\n' (Length calcuation directly over a string)
```
```
RELOP : GT (To check greater than)
```

(This is for a particular statement)
```
a_stat: VAR '=' exp 
     | VAR '=' STR
     | error '\n'
```
```
exp: VAR '[' x ']' (expression can be either an array access)
     |  x   (or expression can be one of these ....)  
     | x '+' x
     | x '-' x
     | x '*' x
     | x '/' x
```
```
x: NUM
     | VAR
```

## Basic Features :fire:

✅ RELATIONAL OPERATORS
✅ INPUT-OUTPUT
✅ IF/ELSE STATEMENTS
✅ FOR AND WHILE LOOPS
✅ FUNCTION CALL
✅ NESTED FUNCTION CALLS
✅ 1-D ARRAY DECLARATIONS

## Advanced Features :fire:

✅ ERROR HANDLING
✅ INBUILT STRING LENGTH FUNCTION
✅ DATATYPES - INT AND STRING
