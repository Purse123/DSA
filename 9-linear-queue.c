#include <stdio.h>
#include <stdlib.h>
#define ITEM_SIZE 20
#define MAX_QUEUE_CAPACITY 40

typedef enum {
  ENQUEUE = 1,
  DEQUEUE,
  TRAVERSE,
  EXIT,
} QueueInstruction;

typedef struct Queue {
  int item[ITEM_SIZE];
  int rear;
  int front;
} Queue;

void Enqueue(Queue *queue, int item) {
  if (queue->rear >= MAX_QUEUE_CAPACITY - 1) {
    printf("Queue is full!!\n");
    return;
  }
  queue->item[++(queue->rear)] = item;
}

void Dequeue(Queue *queue) {
  if (queue->front > queue->rear ) {
    printf("Queue is empty\n");
    return;
  }
  int item = queue->item[queue->front];
  printf("%d is deleted\n", item);
  queue->front++;
}

void Traverse(Queue *queue) {
  if (queue->front > queue->rear) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d\t", queue->item[i]);
  }
  printf("\n");
}

int main() {
  Queue *q = malloc(sizeof(Queue));
  if (q == NULL) {
    printf("Memory allocation failed");
    exit(1);
  }
  q -> rear = -1;
  q -> front = 0;

  int queue_int = 0;
  int value;

  printf("-----------------------------\n");
  printf("Choose the queue operation\n");
  printf("1. ENQUEUE\n2. DEQUEUE\n3. TRAVERSE\n4. EXIT\n");
  printf("-----------------------------\n");

  while(queue_int != 4) {
    printf("Enter the instruction key: ");
    scanf("%d", &queue_int);

    switch (queue_int) {
      case ENQUEUE:
        printf("Enter the value: ");
        scanf("%d", &value);
        Enqueue (q, value);
        break;
      case DEQUEUE:
        Dequeue(q);
        break;
      case TRAVERSE:
        Traverse(q);
        break;
      case EXIT:
        printf("Exiting...\n");
        break;
      default:
        printf("Choose valid option\n");
        break;
    }
  }
  printf("__________________________\n");
  printf("Programmed by: Pierce Neupane\n");
}
