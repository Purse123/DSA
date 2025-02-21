#include <stdio.h>

int factorial(int a) {
  return (a <= 1) ? 1 : a * factorial(a - 1);
}

int main() {
  int n;
  printf("Enter any number: ");
  scanf("%d", &n);

  int result = factorial(n);
  printf("Factorial of n = %d\n", result);
}
