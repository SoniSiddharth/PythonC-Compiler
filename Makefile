all: 
	@bison -d calc.y
	@flex tok.l
	@gcc calc.tab.c lex.yy.c -lfl -lm

help:
	@echo "make : For compiling the code then test any of the following command"
	@echo "make fibonacci"
	@echo "make factorial"
	@echo "make whilefor"
	@echo "make basicio"
	@echo "make errorfunc"
	@echo "make relop"
	@echo "make arraysum"
	@echo "make simplefunction"
	@echo "make stringlen"

fibonacci:
	@./a.out <./testprograms/fibonacci.prog

factorial:
	@./a.out <./testprograms/factorial.prog

whilefor:
	@./a.out <./testprograms/whilefor.prog

basicio:
	@./a.out <./testprograms/basicio.prog

errorfunc:
	@./a.out <./testprograms/errorfunc.prog

relop:
	@./a.out <./testprograms/relop.prog

arraysum:
	@./a.out <./testprograms/arraysum.prog

simplefunction:
	@./a.out <testprograms/simpleFunction.prog

stringlen:
	@./a.out <testprograms/stringlen.prog