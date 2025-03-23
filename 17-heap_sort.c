#include <stdio.h>
#include <stdlib.h>

// Heapify a subtree rooted at index `i`
void heapify(int *arr, int n, int i) {
  int largest = i;  // Root
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}

// Builds a max heap
void buildHeap(int *arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

// Heap sort function
void heapSort(int *arr, int n) {
  buildHeap(arr, n);

  for (int i = n - 1; i > 0; i--) {
    // Move the largest element (root) to the end
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // Restore heap property
    heapify(arr, i, 0);
  }
}

int main() {
  int n;
  printf("Enter no of elements: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    printf("Enter %dth element: ", i);
    scanf("%d", &arr[i]);
  }

  heapSort(arr, n);

  printf("\nAfter sorting:\n[");
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(", ");
    printf("%d", arr[i]);
  }
  printf("]\n");

  free(arr);
  printf("__________________________\n");
  printf("Programmed by: Pierce Neupane\n");
  return 0;
}
