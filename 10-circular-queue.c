#include <stdio.h>
#include <stdbool.h>
#define MAX_QUEUE_CAPACITY 40

typedef enum {
  ENQUEUE = 1,
  DEQUEUE,
  TRAVERSE,
  EXIT,
} QueueInstruction;

typedef struct {
  int rear;
  int front;
  int data[MAX_QUEUE_CAPACITY];
} ciQueue;

void enqueue (ciQueue *q) {
  int value;
  printf("Enter the value: ");
  scanf("%d", &value);

  if (q->front == (q->rear + 1) % MAX_QUEUE_CAPACITY) {
    printf("Queue is full!\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_QUEUE_CAPACITY;
  q->data[q->rear] = value;
}

void dequeue (ciQueue *q) {
  if (q->front == q->rear) {
    printf("Queue is empty\n");
    return;
  }
  q->front = (q->front + 1) % MAX_QUEUE_CAPACITY;
  printf("%d is deleted\n", q->data[q->front]);
}

void traverse (ciQueue *q) {
  if (q->front == q->rear) {
    printf("Queue is empty\n");
    return;
  }

  int i = q->front;
  while (true) {
    i = (i + 1) % MAX_QUEUE_CAPACITY;
    printf("%d\t", q->data[i]);
    if (i == q->rear) break;
  }
  printf("\n");
}

int main() {
  int queue_int = 0;
  ciQueue queue = {
    .front = MAX_QUEUE_CAPACITY - 1,
    .rear = MAX_QUEUE_CAPACITY - 1
  };

  printf("-----------------------------\n");
  printf("Choose the queue operation\n");
  printf("1. ENQUEUE\n2. DEQUEUE\n3. TRAVERSE\n4. EXIT\n");
  printf("-----------------------------\n");

  while(queue_int != 4) {
    printf("Enter the instruction key: ");
    scanf("%d", &queue_int);
    QueueInstruction q = queue_int;

    switch (q) {
      case ENQUEUE:
        enqueue(&queue);
        break;
      case DEQUEUE:
        dequeue (&queue);
        break;
      case TRAVERSE:
        traverse (&queue);
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
