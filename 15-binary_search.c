#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int a, int b, int x) {
  int m;
  if (a <= b) {
    // Prevents integer overflow
    m = a + (b - a) / 2;

    if (x == *(arr + m))
      return m;
    else if (x < *(arr + m))
      return binary_search(arr, a, m - 1, x);
    else
      return binary_search(arr, m + 1, b, x);
  } else {
    return -1;
  }
}

int main() {
  size_t n;
  int x;
  printf("Enter the no of term: ");
  scanf("%zu", &n);
  printf("Enter no to search: ");
  scanf("%d", &x);

  int *arr = (int *)malloc(n * sizeof(int));

  for (size_t i = 0; i < n; ++i) {
    printf("Enter %zuth item: ", i);
    scanf("%d", (arr + i));
  }

  int result = binary_search(arr, 0, n - 1, x);
  if (result == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at pos %d\n", result);
  }
  printf("__________________________\n");
  printf("Programmed by: Pierce Neupane\n");
}
