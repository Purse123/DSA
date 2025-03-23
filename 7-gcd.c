#include <stdio.h>

int gcd(int a, int b) {
  return (b == 0) ? a : gcd (b, a % b);
}

int main() {
  int a, b;
  printf("Enter any two number: \n");
  scanf("%d%d", &a, &b);

  printf("gcd of %d and %d is %d\n", a, b, gcd(a, b));
  printf("__________________________\n");
  printf("Programmed by: Pierce Neupane\n");
}
