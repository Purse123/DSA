#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1   // Marker for an empty slot
#define DELETED -2 // Marker for a deleted slot

typedef enum {
  INSERTION = 1,
  SEARCHING,
  DISPLAY,
  DELETION,
  EXIT
} HASHINGOPERATION;

typedef struct NODE {
  int key;
  int value;
} NODE;

NODE hashTable[TABLE_SIZE];

// Linear probing hash function
#define HASH_FUNCTION(key) (key % TABLE_SIZE)

void insertion(NODE n) {
  // Value of index is determined by
  // a. hash = hash_func(key)
  // b. index = hash % array_size
  int index = HASH_FUNCTION(n.key);
  int originalIndex = index;

  while (hashTable[index].key != EMPTY && hashTable[index].key != DELETED) {
    index = (index + 1) % TABLE_SIZE;

    if (index == originalIndex) {
      printf("Hash table is full! Cannot insert (%d, %d)\n", n.key, n.value);
      return;
    }
  }

  hashTable[index].key = n.key;
  hashTable[index].value = n.value;
  printf("Inserted (%d, %d) at index %d\n", n.key, n.value, index);
}

void search(int key) {
  int index = HASH_FUNCTION(key);
  int originalIndex = index;

  while (hashTable[index].key != EMPTY) {
    if (hashTable[index].key == key) {
      printf("Found (%d, %d) at index %d\n", key, hashTable[index].value, index);
      return;
    }

    index = (index + 1) % TABLE_SIZE;

    if (index == originalIndex) break;
  }

  printf("Key %d not found in the hash table.\n", key);
}

void deletion(int key) {
  int index = HASH_FUNCTION(key);
  int originalIndex = index;

  while (hashTable[index].key != EMPTY) {
    if (hashTable[index].key == key) {
      hashTable[index].key = DELETED;
      printf("Deleted key %d from index %d\n", key, index);
      return;
    }

    index = (index + 1) % TABLE_SIZE;

    if (index == originalIndex) break; // Full cycle completed
  }
  printf("Key %d not found. Cannot delete.\n", key);
}

// Function to display the hash table
void display() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hashTable[i].key == EMPTY) {
      printf("Index %d: EMPTY\n", i);
    } else if (hashTable[i].key == DELETED) {
      printf("Index %d: DELETED\n", i);
    } else {
      printf("Index %d: (%d, %d)\n", i, hashTable[i].key, hashTable[i].value);
    }
  }
}

int main() {
  int deleteKey, searchKey;
  int op;
  NODE new_node;

  // Initialize hash table
  for (int i = 0; i < TABLE_SIZE; i++) {
    hashTable[i].key = EMPTY;
    hashTable[i].value = 0;
  }

  printf("-----------------------------\n");
  printf("Choose a hashing operation\n");
  printf("1. INSERTION\n2. SEARCHING\n3. DISPLAY\n4. DELETION\n5. EXIT\n");
  printf("-----------------------------\n");

  while (1) {
    printf("Enter the instruction key: ");
    scanf("%d", &op);

    switch (op) {
      case INSERTION:
        printf("Enter key: ");
        scanf("%d", &new_node.key);
        printf("Enter value: ");
        scanf("%d", &new_node.value);
        insertion(new_node);
        break;

      case SEARCHING:
        printf("Enter key to search: ");
        scanf("%d", &searchKey);
        search(searchKey);
        break;

      case DISPLAY:
        display();
        break;

      case DELETION:
        printf("Enter key to delete: ");
        scanf("%d", &deleteKey);
        deletion(deleteKey);
        break;

      case EXIT:
        printf("Exiting...\n");
        return 0;

      default:
        printf("Choose a valid option.\n");
        break;
    }
  }
}
