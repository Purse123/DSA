#include <stdio.h>
#include <stdlib.h>

void bubbleSort (int *a, int sz) {
  int temp;
  for (int i = 0; i < sz - 1; i++) {
    for (int j = 0; j < sz - i - 1; j++) {
      temp = a[j];
      if (a[j] > a[j + 1]) {
	a[j] = a[j + 1];
	a[j + 1] = temp;
      }
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
  bubbleSort(arr, n);

  printf("After sort: ");
  printf("\n[");
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(", ");
    printf("%d", arr[i]);
  }
  printf("]\n");
  free(arr);
  return 0;
}
