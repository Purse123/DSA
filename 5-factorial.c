#include <stdio.h>

size_t factorial(size_t a) {
  return (a <= 1) ? 1 : a * factorial(a - 1);
}

int main() {
  size_t n;
  printf("Enter any number: ");
  scanf("%zu", &n);

  printf("Factorial of n = %zu\n", factorial(n));
}
