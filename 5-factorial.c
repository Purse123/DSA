#include <stdio.h>
int factorial(int a) {
  if (a == 0) {
    return 1;
  }
  else if (a > 1) {
    return a * factorial(a - 1);
  }
}

int main() {
  int n;
  printf("Enter any number: ");
  scanf("%d", &n);
  int result = factorial(n);
  printf("Factorial of n = %d\n", result);
}
