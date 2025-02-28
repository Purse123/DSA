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

typedef struct Node {
  struct Node *next;
  int data;
} QueueNode;

typedef struct Queue {
  QueueNode *front;
  QueueNode *rear;
} Queue;

Queue *q;

// insert at end
void Enqueue(int item) {
  QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
  if (!new_node) perror("Failed to allocate memory");

  new_node->data = item;
  new_node->next = NULL;

  if (q->front == NULL) {
    q->front = new_node;
    q->rear = new_node;
  } else {
    q->rear->next = new_node;
    q->rear = new_node;
  }
}

// delete at first
void Dequeue() {
  if (q->front == NULL) {
    printf("Queue is empty\n");
    return;
  }

  QueueNode *temp_node = q->front;
  printf("%d is deleted.\n", temp_node->data);
  q->front = q->front->next;
  free(temp_node);

  if (q->front == NULL) {
    q->rear = NULL;
  }
}

// traverse using recursion need helper function
void Traverse() {
  if (q->front == NULL) {
    printf("Queue is empty.\n");
    return;
  }

  QueueNode *temp_node = q->front;
  while (temp_node != NULL) {
    printf("%d\t", temp_node->data);
    temp_node = temp_node->next;
  }
  printf("\n");
}

int main() {
  q = (Queue*)malloc(sizeof(Queue));
  if (!q) perror("Failed to allocate memory");
  q->front = NULL;
  q->rear = NULL;

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
        Enqueue (value);
        break;
      case DEQUEUE:
        Dequeue();
        break;
      case TRAVERSE:
        Traverse();
        break;
      case EXIT:
        printf("Exiting...\n");
        break;
      default:
        printf("Choose valid option\n");
        break;
    }
  }
}
