#include <stdio.h>
#include <stdlib.h>

int linear_search(int *arr, size_t size, int x) {
  for (size_t i = 0; i < size; ++i) {
    if (*(arr + i) == x)
      return (int)i;
  }
  return -1;
}

int main () {
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

  int result = linear_search(arr, n, x);
  if (result == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at pos %d\n", result);
  }
}
