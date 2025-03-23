#include <stdio.h>
#include <stdlib.h>

typedef enum {
  INSERTION = 1,
  DELETION,
  TRAVERSE,
  EXIT
} Operations;

typedef struct Node{
  struct Node *next;
  int data;
}NODE;

typedef struct linkedList {
  NODE *first;
  NODE *last;
} linkedList;

linkedList *l;

void insertion_beginning (int value) {
  // Creating singly linked list
  NODE *new_node = (NODE*)malloc(sizeof(NODE));
  if (!new_node) perror("Failed to allocate memory");

  new_node->data = value;

  if (l->first == NULL) {
    new_node->next = NULL;
    l->first = new_node;
    l->last = new_node;
  } else {
    new_node->next = l->first;
    l->first = new_node;
  }
}

void insertion_ending (int value) {
  // Creating singly linked list
  NODE *new_node = (NODE*)malloc(sizeof(NODE));
  if (!new_node) perror("Failed to allocate memory");

  new_node->data = value;
  new_node->next = NULL;
  
  if (l->first == NULL) {
    new_node->next = NULL;
    l->first = new_node;
    l->last = new_node;
  } else {
    l->last->next = new_node;
    l->last = new_node;
  }
}

void insertion_specific_position (int value, int pos) {
  // Creating singly linked list
  NODE *temp;
  NODE *new_node = (NODE*)malloc(sizeof(NODE));
  if (!new_node) perror("Failed to allocate memory");
  new_node->data = value;
  
  if (l->first == NULL) {
    l->first = new_node;
    l->last = new_node;
  } else {
    temp = l->first;
    for (int i = 1; i< pos - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
}

void deletion_beginning() {
  if (l->first == NULL) {
    printf("List is empty! Nothing to delete.\n");
    return;
  }

  NODE *temp = l->first;
  l->first = l->first->next;

  if (l->first == NULL) l->last = NULL; // If the list had only one node, update last pointer

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
  l->last->next = NULL;
  printf("Deleted from end.\n");
}

void deletion_specific_position(int pos) {
  if (l->first == NULL) {
    printf("List is empty! Nothing to delete.\n");
    return;
  }

  if (pos < 1) {
    printf("Invalid position!\n");
    return;
  }

    // Case 1: Delete the first node
  if (pos == 1) {
    deletion_beginning();
    return;
  }

  NODE *temp = l->first;
  NODE *prev = NULL;
  int count = 1;

  // Traverse to the node at the given position
  while (temp != NULL && count < pos) {
    prev = temp;
    temp = temp->next;
    count++;
  }

  // If position is out of bounds
  if (temp == NULL) {
    printf("Position out of range!\n");
    return;
  }

  // Case 2: Delete the last node
  if (temp == l->last) {
    deletion_ending();
    return;
  }

  // Case 3: Delete a node in the middle
  prev->next = temp->next;
  free(temp);
  printf("Deleted node at position %d.\n", pos);
}

void traversal() {
  NODE *temp;
  temp = l->first;

  if (l->first == NULL) {
    printf("Empty linked list\n");
    return;
  } else {
    while (temp != NULL) {
      printf("%d\t", temp->data);
      temp = temp->next;
    }
  }
  printf("\n");
}

int main() {
  int op_int = 0, item, pos;
  l = (linkedList*)malloc(sizeof(linkedList));
  if (l == NULL) perror("Failed to allocate memory for linked list");

  l->first = NULL;
  l->last = NULL;

  printf("-----------------------------\n");
  printf("Choose the queue operation\n");
  printf("1. Insertion\n2. Deletion\n3. TRAVERSE\n4. EXIT\n");
  printf("-----------------------------\n");

  while(op_int != 4) {
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

	switch(op_int) {
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

	switch(op_int) {
	    case 1:
	      deletion_beginning(item);
	      break;
	    case 2:
	      deletion_ending(item);
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
  printf("__________________________\n");
  printf("Programmed by: Pierce Neupane\n");
}
