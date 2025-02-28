#include <stdio.h>

typedef enum {
  ENQUEUE = 1,
  DEQUEUE,
  TRAVERSE,
  EXIT,
} Operations;

void insertion();
void deletion();
void traversal();

int main() {
  int op_int = 0;

  printf("-----------------------------\n");
  printf("Choose the queue operation\n");
  printf("1. Creation\n2. Insertion\n3. Deletion\n4. TRAVERSE\n5. EXIT\n");
  printf("-----------------------------\n");

  while(op_int != 4) {
    printf("Enter the instruction key: ");
    scanf("%d", &op_int);
    Operations q = op_int;

    switch (q) {
      case ENQUEUE:
        insertion();
        break;
      case 2:
        deletion();
        break;
      case 3:
        traversal();
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Choose valid option\n");
        break;
    }
  }
}
