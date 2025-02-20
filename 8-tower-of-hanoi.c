#include <stdio.h>
#define NO_OF_DISK 3

void TOH(int n, char from, char temp, char to) {
  if (n > 0) {
    TOH(n - 1, from, to, temp);
    printf("Move the disk %d from %c to %c\n", n, from, to);
    TOH(n - 1, temp, from, to);
  }
}

int main() {
  char source = 'S';
  char destination = 'D';
  char temporary = 'T';
  TOH(NO_OF_DISK, source, temporary, destination);
}
