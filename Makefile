# CC=time gcc
CC=gcc
CFLAGS= -Wall -Wextra

all: q1 q2 q3 q5 q6 q7 q8 q9a q9b
q1: 1-stack-operation.c
	$(CC) -o 1-stack-operation 1-stack-operation.c $(CFLAGS)
q2: 2-stack-opp-pointer.c
	$(CC) -o 2-stack-opp-pointer 2-stack-opp-pointer.c $(CFLAGS)
q3: 3-postfix-exp.c
	$(CC) -o 3-postfix-exp 3-postfix-exp.c $(CFLAGS)
q4: 4-prefix-exp.c
	$(CC) -o 4-prefix-exp 4-prefix-exp.c $(CFLAGS)
q5: 5-factorial.c
	$(CC) -o 5-factorial 5-factorial.c $(CFLAGS)
q6: 6-fibonacci.c
	$(CC) -o 6-fibonacci 6-fibonacci.c $(CFLAGS)
q7: 7-gcd.c
	$(CC) -o 7-gcd 7-gcd.c $(CFLAGS)
q8: 8-tower-of-hanoi.c
	$(CC) -o 8-tower-of-hanoi 8-tower-of-hanoi.c $(CFLAGS)
q9a: 9-linear-queue.c
	$(CC) -o 9-linear-queue 9-linear-queue.c $(CFLAGS)
q9b: 9-linear-queue-pointer.c
	$(CC) -o 9-linear-queue-pointer 9-linear-queue-pointer.c
q10: 10-circular-queue.c
	$(CC) -o 10-circular-queue 10-circular-queue.c $(CFLAGS)
q11: 11-singly_linked_list.c
	$(CC) -o 11-singly_linked_list 11-singly_linked_list.c $(CFLAGS)
q12: 12-circular-linked-list.c
	$(CC) -o 12-circular-linked-list 12-circular-linked-list.c $(CFLAGS)
q13: 13-binary-tree.c
	$(CC) -o 13-binary-tree 13-binary-tree.c $(CFLAGS)
q14: 14-linear_search.c
	$(CC) -o 14-linear_search 14-linear_search.c $(CFLAGS)
q15: 15-binary_search.c
	$(CC) -o 15-binary_search 15-binary_search.c $(CFLAGS)
q16: 16-hashing_implement.c
	$(CC) -o 16-hashing_implement 16-hashing_implement.c $(CFLAGS)

clean:
	rm -f 9-linear-queue 9-linear-queue-pointer 8-tower-of-hanoi 4-prefix-exp 2-stack-opp-pointer 1-stack-operation 3-postfix-exp 5-factorial 6-fibonacci 7-gcd 10-circular-queue 11-singly_linked_list 13-binary-tree 12-circular-linked-list 14-linear_search 16-hashing_implement 15-binary_search
