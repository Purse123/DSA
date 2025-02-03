#include <stdio.h>

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

int main() {
  char op;
  initialize_precedence();
  /* char exp[40]; */
/*   printf("Enter the infix expression: "); */
/*   scanf("%s", exp); */
  printf("Enter the operator: ");
  scanf("%c", &op);
  printf("Precedence: %d\n", PRECEDENCE(op));
}
