#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *left;
  struct NODE *right;
} NODE;

NODE* insert_node(NODE *head, int val) {
  // create root node
  if (!head) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node) {
      perror("allocation failed");
      return NULL;
    }

    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
  }
  // insert into the root
  if (val < head->data) {
    head->left = insert_node(head->left, val);
  }
  else {
    head->right = insert_node(head->right, val);
  }
  return head;
}

void preorder(NODE *root) {
  if (root) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(NODE *root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void postOrder(NODE *root) {
  if (root) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  int inp = 0, item;
  NODE *root = NULL;

  printf("_________________________________\n");
  printf("1. Insert value\n2. In-order traverse\n3. Pre-order traverse\n4. Post-order traverse\n5. Exit\n"); 
  printf("_________________________________\n");

  while(inp != 5) {
    printf("Enter choice: ");
    scanf("%d", &inp);

    switch (inp) {
    case 1:
      printf("Enter value: ");
      scanf("%d", &item);
      root = insert_node(root, item);
      break;
    case 2:
      inorder(root);
      printf("\n");
      break;
    case 3:
      preorder(root);
      printf("\n");
      break;
    case 4:
      postOrder(root);
      printf("\n");
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid input\n");
    }
  }
  return 0;
}
