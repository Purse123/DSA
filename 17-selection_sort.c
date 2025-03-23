#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int *a, int sz) {
  int index;
  for (int i = 0; i < sz - 1; i++) {
    index = i;
    for (int j = i + 1; j < sz; j++) {
      if (a[j] < a[index]) {
	index = j;
      }
    }

    if (index != i) {
      swap(a + i, a + index);
    }
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
  selectionSort(arr, n);

  printf("\nAfter sort: ");
  printf("\n[");
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
