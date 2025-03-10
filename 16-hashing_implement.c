#include <stdio.h>
#include <stdlib.h>

struct HashNode {
  int key;
  int value;
};

const int capacity = 20;
int size = 0;

struct HashNode** arr;
struct HashNode* dummy;

void insert(int key, int V) {
  struct HashNode* temp = (struct HashNode*)malloc(sizeof(struct HashNode));
  temp->key = key;
  temp->value = V;

  int hashIndex = key % capacity;

  while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
    hashIndex++;
    hashIndex %= capacity;
  }

  if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
    size++;

  arr[hashIndex] = temp;
}

int delete (int key) {
  int hashIndex = key % capacity;

  while (arr[hashIndex] != NULL) {
    if (arr[hashIndex]->key == key) {
      arr[hashIndex] = dummy;
      size--;
      return 1;
    }
    hashIndex++;
    hashIndex %= capacity;
  }
  return 0;
}

int find(int key) {
  int hashIndex = (key % capacity);
  int counter = 0;

  while (arr[hashIndex] != NULL) {
    if (counter++ > capacity)
      break;
    if (arr[hashIndex]->key == key)
      return arr[hashIndex]->value;
    hashIndex++;
    hashIndex %= capacity;
  }
  return -1;
}

int main() {
  arr = (struct HashNode**)malloc(sizeof(struct HashNode*) * capacity);
  for (int i = 0; i < capacity; i++)
    arr[i] = NULL;

  dummy = (struct HashNode*)malloc(sizeof(struct HashNode));
  dummy->key = -1;
  dummy->value = -1;

  int choice, key, value;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Find\n");
    printf("3. Delete\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter key and value: ");
        scanf("%d %d", &key, &value);
        insert(key, value);
        printf("Inserted (%d, %d)\n", key, value);
        break;
      case 2:
        printf("Enter key to find: ");
        scanf("%d", &key);
        value = find(key);
        if (value != -1)
          printf("Value of key %d = %d\n", key, value);
        else
          printf("Key %d does not exist\n", key);
        break;
      case 3:
        printf("Enter key to delete: ");
        scanf("%d", &key);
        if (delete(key))
          printf("Key %d deleted successfully\n", key);
        else
          printf("Key %d does not exist\n", key);
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice. Try again.\n");
    }
  }
}
