#include <stdio.h>
int fibonacci (int n) {
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return fibonacci( n - 1 ) + fibonacci(n - 2);
  }
}
int main() {
  int n, result = 0;
  printf("Enter the no of term: ");
  scanf("%d", &n);
  printf("fibonacci upto nth term is \n");
  for(int i = 0; i < n; i++ ) {
    printf("%d\t", fibonacci(i));
  }
  printf("\n");
}
