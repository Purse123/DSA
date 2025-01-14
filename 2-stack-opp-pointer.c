/**
  Copyright (c) 2025 Author. All Rights Reserved.
**/

#include <stdio.h>
#include <stdlib.h>
typedef enum {
  STACK_PUSH = 1,
  STACK_POP,
  STACK_TRAVERSE,
  EXIT,
} STACK_OPERATION;

int MAXSIZE;
int tos = -1;
int *STACK_ITEM;

void PUSH(void) {
  int value;
  if (tos == MAXSIZE - 1) {
    printf("Stack is full\n");
    return;
  } else {
    printf("Enter the value: ");
    scanf("%d", &value);
    /*STACK_ITEM[++tos] = value;*/
    tos++;
    *(STACK_ITEM + tos ) = value;
  }
}

void POP(void) {
  if (tos == -1) {
    printf("Stack is empty\n");
    return;
  } else {
    printf("value %d is deleted\n", *( STACK_ITEM + tos));
    tos--;
  }
}

void TRAVERSE(void) {
  if (tos == -1) {
    printf("Stack is empty\n");
    return;
  } else {
    for(int i = tos; i>=0; i--) {
      printf("%d\n", *(STACK_ITEM + i));
    }
  }
}

int main() {
  int stack_int;
  printf("Enter the max size: ");
  scanf("%d", &MAXSIZE);
  STACK_ITEM = (int *)malloc(MAXSIZE * sizeof(int));

  printf("-----------------------------\n");
  printf("Choose the stack operation\n");
  printf("1. PUSH\n2. POP\n3. TRAVERSE\n4. EXIT\n");
  printf("-----------------------------\n");
  while (stack_int != 4) {

    printf("Enter the corresponding integer: ");
    scanf("%d", &stack_int);

    STACK_OPERATION var = stack_int;

    switch (var) {
    case 1:
        PUSH();
      break;
    case 2:
        POP();
      break;
    case 3:
        TRAVERSE();
      break;
    case 4:
        printf("Exiting...\n");
      break;
    default:
      printf("Input error\n");
    }
  }
}
