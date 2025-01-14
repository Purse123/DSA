Copyright (c) 2025 Author. All Rights Reserved.
```c
#include<stdio.h>
typedef enum {
  STACK_PUSH = 1,
  STACK_POP,
  STACK_TRAVERSE,
  EXIT,
}STACK_OPERATION;

int main() {
  int stack_int;
  printf("-----------------------------\n");
  printf("Choose the stack operation\n");
  printf("1. PUSH\n2. POP\n3. TRAVERSE\n4. EXIT\n");
  printf("-----------------------------\n");
  printf("Enter the corresponding integer: ");
  scanf("%d", &stack_int);

  STACK_OPERATION var = stack_int;

  switch (var) {
    case 1:
    printf("Push\n");
    break;
    case 2:
    printf("Pop\n");
    break;
    case 3:
    printf("Traverse\n");
    break;
    case 4:
            return 1;
      break;
    break;
      default:
    printf("Input error");
  }
}
```
