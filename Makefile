CC=gcc
CFLAGS= -Wall

all: q1 q2 q3
q1: 1-stack-operation.c
	time $(CC) -o 1-stack-operation 1-stack-operation.c $(CFLAGS)
q2: 2-stack-opp-pointer.c
	time $(CC) -o 2-stack-opp-pointer 2-stack-opp-pointer.c $(CFLAGS)
q3: 3-postfix-exp.c
	time $(CC) -o 3-postfix-exp 3-postfix-exp.c $(CFLAGS)
clean:
	rm -f 2-stack-opp-pointer 1-stack-operation 3-postfix-exp
