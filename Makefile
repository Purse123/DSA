# CC=time gcc
CC=gcc
CFLAGS= -Wall -Wextra

all: q1 q2 q3 q5 q6 q7 q8 q9a q9b q10 q11 q12 q13 q14 q15 q16 q17a q17b q17c q17d q17e q17f q18a q18b q19 q20

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
17a: 17-bubble_sort.c 
	$(CC) 17-bubble_sort.c -o 17-bubble_sort $(CFLAGS)
17b: 17-insertion_sort.c
	$(CC) 17-insertion_sort.c -o 17-insertion_sort $(CFLAGS)
17c: 17-selection_sort.c
	$(CC) 17-selection_sort.c -o 17-selection_sort $(CFLAGS)
17d: 17-quick_sort.c
	$(CC) 17-quick_sort.c -o 17-quick_sort $(CFLAGS)
17e: 17-merge_sort.c
	$(CC) 17-merge_sort.c -o 17-merge_sort $(CFLAGS)
17f: 17-heap_sort.c
	$(CC) 17-heap_sort.c -o 17-heap_sort $(CFLAGS)
q18a: 18-bfs.c
	$(CC) 18-bfs.c -o 18-bfs $(CFLAGS)
q18b: 18-dfs.c
	$(CC) 18-dfs.c -o 18-dfs $(CFLAGS)
q19: 19-kruskal.c 
	$(CC) 19-kruskal.c -o 19-kruskal $(CFLAGS)
q20: 20-dijkstra.c 
	$(CC) 20-dijkstra.c -o 20-dijkstra $(CFLAGS)

clean:
	rm -f 9-linear-queue 9-linear-queue-pointer 8-tower-of-hanoi 4-prefix-exp 2-stack-opp-pointer 1-stack-operation 3-postfix-exp 5-factorial 6-fibonacci 7-gcd 10-circular-queue 11-singly_linked_list 13-binary-tree 12-circular-linked-list 14-linear_search 16-hashing_implement 15-binary_search 17-bubble_sort 17-insertion_sort 17-selection_sort 17-quick_sort 17-merge_sort 17-heap_sort 18-bfs 18-dfs 19-kruskal 20-dijkstra
