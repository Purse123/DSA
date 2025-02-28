#include <stdio.h>
typedef enum {
  STACK_PUSH = 1,
  STACK_POP,
  STACK_TRAVERSE,
  EXIT,
} STACK_OPERATION;

#define MAXSIZE 10
int STACK_ITEM[MAXSIZE], tos = -1;

void PUSH(void) {
  int value;
  if (tos == MAXSIZE) {
    printf("Stack is full\n");
    return;
  } else {
    printf("Enter the value: ");
    scanf("%d", &value);
    STACK_ITEM[++tos] = value;
  }
}

void POP(void) {
  if (tos == -1) {
    printf("Stack is empty\n");
    return;
  } else {
    printf("value %d is deleted\n", STACK_ITEM[tos--]);
  }
}

void TRAVERSE(void) {
  if (tos == -1) {
    printf("Stack is empty\n");
    return;
  } else {
    for(int i = tos; i>=0; i--) {
      printf("%d\n", STACK_ITEM[i]);
    }
  }
}

int main() {
  int stack_int = 0;

  printf("-----------------------------\n");
  printf("Choose the stack operation\n");
  printf("1. PUSH\n2. POP\n3. TRAVERSE\n4. EXIT\n");
  printf("-----------------------------\n");
  while (stack_int != 4) {

    printf("Enter the corresponding integer: ");
    scanf("%d", &stack_int);

    STACK_OPERATION var = stack_int;

    switch (var) {
    case STACK_PUSH:
        PUSH();
      break;
    case STACK_POP:
        POP();
      break;
    case STACK_TRAVERSE:
        TRAVERSE();
      break;
    case EXIT:
        printf("Exiting...\n");
      break;
    default:
      printf("Input error\n");
    }
  }
}
