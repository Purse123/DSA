#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int sz) {
  int temp, j;
  for (int i = 1; i < sz; ++i) {
    temp = a[i];
    j = i - 1;

    while (j >= 0 && a[j] > temp) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = temp;
  }
}

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  insertionSort(arr, n);

  printf("\nAfter sorting: [");
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
