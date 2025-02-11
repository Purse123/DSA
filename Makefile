CC=gcc
CFLAGS= -Wall

all: q1 q2 q3 q5 q6 q7
q1: 1-stack-operation.c
	time $(CC) -o 1-stack-operation 1-stack-operation.c $(CFLAGS)
q2: 2-stack-opp-pointer.c
	time $(CC) -o 2-stack-opp-pointer 2-stack-opp-pointer.c $(CFLAGS)
q3: 3-postfix-exp.c
	time $(CC) -o 3-postfix-exp 3-postfix-exp.c $(CFLAGS)
q4: 4-prefix-exp.c
	$(CC) -o 4-prefix-exp 4-prefix-exp.c $(CFLAGS)
q5: 3-postfix-exp.c
	time $(CC) -o 5-factorial 5-factorial.c $(CFLAGS)
q6: 3-postfix-exp.c
	time $(CC) -o 6-fibonacci 6-fibonacci.c $(CFLAGS)
q7: 3-postfix-exp.c
	time $(CC) -o 7-gcd 7-gcd.c $(CFLAGS)
clean:
	rm -f 4-prefix-exp 2-stack-opp-pointer 1-stack-operation 3-postfix-exp 5-factorial 6-fibonacci 7-gcd
