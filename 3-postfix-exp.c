#include <stdio.h>
#include <string.h>

#define MAX_ASCII 128
int PRECEDENCE_TABLE[MAX_ASCII] = {0};

#define POST_STACK_SIZE 20
#define OP_STACK_SIZE 20
char POST_STACK[POST_STACK_SIZE];
char OP_STACK[OP_STACK_SIZE];

// CHECK FOR OP AND GIVE PRECEDENCE, IT IS HOLY FUCKING O(N^2)
/*
typedef struct {
  char op; int op_precedence;
} OPERATOR;
OPERATOR PRECEDENCE_TABLE[] {
  {'^', 5}, {'$', 5}, {'/', 4}, {'*', 4},
  {'+', 3}, {'-', 3}, {'(', 0}, {')', 0},
}
*/

void initialize_precedence() {
    PRECEDENCE_TABLE['^'] = 5;
    PRECEDENCE_TABLE['$'] = 5;
    PRECEDENCE_TABLE['/'] = 4;
    PRECEDENCE_TABLE['*'] = 4;
    PRECEDENCE_TABLE['+'] = 3;
    PRECEDENCE_TABLE['-'] = 3;
    PRECEDENCE_TABLE['('] = 0;
    PRECEDENCE_TABLE[')'] = 0;
}
// Take char and return ASCII, at best wil be O(1)
#define PRECEDENCE(op) PRECEDENCE_TABLE[(int)op]

void postfix(char *expression, int expLength) {
  for(size_t i = 0; i < expLength; i++) {
    char c = expression[i];
    if (c >= 65 && c <= 90) {
      printf("Character\n");
    }
    else if (c == 40 ) {
      printf("Open Paranthesis\n");
    }
    else if (c == 41 ) {
      printf("Close Paranthesis\n");
    }
    else if (c == 94 || c == 36 ||c == 47 ||c == 42 ||c == 43 ||c == 45) {
      printf("Arithmethics\n");
    }
    else {
      printf("Invalid Character\n");
    }
  }
}
int main() {
  char exp[40];
  initialize_precedence();
  printf("Enter the infix expression: ");
  scanf("%s", exp);
  size_t expLen = strlen(exp);
  postfix(exp, expLen);


  /* printf("Enter the operator: "); */
/*   scanf("%c", &op); */
/*   printf("Precedence: %d\n", PRECEDENCE(op)); */
}
