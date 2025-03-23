#include <stdio.h>
#include <stdlib.h>

typedef enum {
  INSERTION = 1,
  DELETION,
  TRAVERSE,
  EXIT
} Operations;

typedef struct Node {
  struct Node *next;
  int data;
} NODE;

typedef struct linkedList {
  NODE *first;
  NODE *last;
} linkedList;

linkedList *l;

void insertion_beginning(int value) {
  NODE *new_node = (NODE*)malloc(sizeof(NODE));
  if (!new_node) {
    perror("Failed to allocate memory");
    return;
  }
  new_node->data = value;

  if (l->first == NULL) {
    new_node->next = new_node;
    l->first = new_node;
    l->last = new_node;
  } else {
    new_node->next = l->first;
    l->first = new_node;
    l->last->next = l->first;
  }
}

void insertion_ending(int value) {
  NODE *new_node = (NODE*)malloc(sizeof(NODE));
  if (!new_node) {
    perror("Failed to allocate memory");
    return;
  }
  new_node->data = value;

  if (l->first == NULL) {
    l->first = new_node;
    l->last = new_node;
    new_node->next = new_node;
  } else {
    l->last->next = new_node;
    l->last = new_node;
    new_node->next = l->first;
  }
}

void insertion_specific_position(int value, int pos) {
  NODE *new_node = (NODE*)malloc(sizeof(NODE));
  if (!new_node) {
    perror("Failed to allocate memory");
    return;
  }
  new_node->data = value;

  if (l->first == NULL) {
    new_node->next = new_node;
    l->first = new_node;
    l->last = new_node;
    return;
  }

  if (pos == 1) {
    new_node->next = l->first;
    l->first = new_node;
    l->last->next = new_node;
    return;
  }

  NODE *temp = l->first;
  int count = 1;
  while (count < pos - 1 && temp->next != l->first) {
    temp = temp->next;
    count++;
  }

  if (count != pos - 1) {
    printf("Invalid position\n");
    free(new_node);
    return;
  }

  new_node->next = temp->next;
  temp->next = new_node;

  if (temp == l->last)
    l->last = new_node;
}

void deletion_beginning() {
  if (l->first == NULL) {
    printf("List is empty! Nothing to delete.\n");
    return;
  }

  NODE *temp = l->first;
  
  if (l->first == l->last) { 
    l->first = NULL;
    l->last = NULL;
  } else {
    l->first = l->first->next;
    l->last->next = l->first;
  }

  free(temp);
  printf("Deleted from beginning.\n");
}

void deletion_ending() {
  if (l->first == NULL) {
    printf("List is empty! Nothing to delete.\n");
    return;
  }

  if (l->first == l->last) { 
    free(l->first);
    l->first = NULL;
    l->last = NULL;
    printf("Deleted last remaining node.\n");
    return;
  }

  NODE *temp = l->first;
  while (temp->next != l->last) {
    temp = temp->next;
  }

  free(l->last);
  l->last = temp;
  l->last->next = l->first;
  printf("Deleted from end.\n");
}

void deletion_specific_position(int pos) {
  if (l->first == NULL) {
    printf("List is empty! Nothing to delete.\n");
    return;
  }

  if (pos == 1) {
    deletion_beginning();
    return;
  }

  NODE *temp = l->first;
  NODE *prev = NULL;
  int count = 1;

  while (count < pos && temp->next != l->first) {
    prev = temp;
    temp = temp->next;
    count++;
  }

  if (count != pos) {
    printf("Position out of range!\n");
    return;
  }

  prev->next = temp->next;
  
  if (temp == l->last) {
    l->last = prev;
  }

  free(temp);
  printf("Deleted node at position %d.\n", pos);
}

void traversal() {
  if (l->first == NULL) {
    printf("Empty linked list\n");
    return;
  }

  NODE *temp = l->first;
  do {
    printf("%d\t", temp->data);
    temp = temp->next;
  } while (temp != l->first);
  printf("\n");
}

int main() {
  int op_int = 0, item, pos;
  l = (linkedList*)malloc(sizeof(linkedList));
  if (l == NULL) {
    perror("Failed to allocate memory for linked list");
    return 1;
  }

  l->first = NULL;
  l->last = NULL;

  printf("-----------------------------\n");
  printf("Choose the queue operation\n");
  printf("1. Insertion\n2. Deletion\n3. TRAVERSE\n4. EXIT\n");
  printf("-----------------------------\n");

  while (op_int != 4) {
    printf("\nEnter the instruction key: ");
    scanf("%d", &op_int);
    Operations q = op_int;

    switch (q) {
      case INSERTION:
        printf("Enter item: ");
        scanf("%d", &item);
        printf("\nChoose the Insertion operation\n");
        printf("1. Insertion at Beginning\n2. Insertion at End\n3. Insertion at Specific position\n");
        scanf("%d", &op_int);

        switch (op_int) {
          case 1:
            insertion_beginning(item);
            break;
          case 2:
            insertion_ending(item);
            break;
          case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            insertion_specific_position(item, pos);
            break;
          default:
            printf("Not valid operation\n");
            break;
        }
        break;
      case DELETION:
        printf("\nChoose the Deletion operation\n");
        printf("1. Deletion at Beginning\n2. Deletion at End\n3. Deletion at Specific position\n");
        scanf("%d", &op_int);

        switch (op_int) {
          case 1:
            deletion_beginning();
            break;
          case 2:
            deletion_ending();
            break;
          case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletion_specific_position(pos);
            break;
          default:
            printf("Not valid operation\n");
            break;
        }
        break;
      case TRAVERSE:
        traversal();
        break;
      case EXIT:
        printf("Exiting...\n");
        break;
      default:
        printf("Choose valid option\n");
        break;
    }
  }
  
  free(l);
  printf("__________________________\n");
  printf("Programmed by: Pierce Neupane\n");
  return 0;
}
