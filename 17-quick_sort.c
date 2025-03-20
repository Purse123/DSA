#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int low, int high) {
  int x = low, y = high;
  int pivot = arr[low];

  while (x < y) {
    while (x <= high && arr[x] <= pivot) {
      x++;
    }
    while (arr[y] > pivot) {
      y--;
    }
    if (x < y)
      swap(arr + x, arr + y);
  }

  arr[low] = arr[y];
  arr[y] = pivot;
  return y;
}

void quickSort(int *arr, int l, int r) {
  int p;
  if (l < r) {
    p = partition(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
  }
}

int main() {
  int n;
  printf("Enter no of element: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    printf("Enter %dth element: ", i);
    scanf("%d", arr + i);
  }
  quickSort(arr, 0, n - 1);

  printf("\nAfter sort: ");
  printf("\n[");
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(", ");
    printf("%d", arr[i]);
  }
  printf("]\n");
  free(arr);
  return 0;
}
