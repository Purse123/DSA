#include <stdio.h>
#include <string.h>

#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])

#define MAX_ASCII 128
int PRECEDENCE_TABLE[MAX_ASCII] = {0};

#define POST_STACK_SIZE 20
#define OP_STACK_SIZE 20
char POST_STACK[POST_STACK_SIZE];
int post_index = -1;
char OP_STACK[OP_STACK_SIZE];
int tos = -1;

// stack function
void stack_push(char);
char stack_pop();
char stack_display();

// CHECK FOR OP AND GIVE PRECEDENCE, IT IS HOLY O(N^2)
/*
typedef struct {
  char op; int op_precedence;
} OPERATOR;
OPERATOR PRECEDENCE_TABLE[] = {
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
      printf("Character: %c\n", c);
      POST_STACK[++post_index] = c;
    }
    else if (c == 40 ) {
      printf("Open Paranthesis\n");
      stack_push(c);
    }
    else if (c == 41 ) {
      printf("Close Paranthesis\n");
      while (tos != -1 && stack_display() != 40) {
	POST_STACK[++post_index] = stack_pop();
      }
      stack_pop();           // remove `(`
    }
    else if (c == 94 || c == 36 ||c == 47 ||c == 42 ||c == 43 ||c == 45) {
      printf("Arithmethics\n");
      while (tos != -1 && PRECEDENCE(stack_display()) >= PRECEDENCE(c) && stack_display() != '(') {
	POST_STACK[++post_index] = stack_pop();
      }
      stack_push(c);
    }
    else {
      printf("Invalid Character\n");
      return;
    }
  }

  while (tos != -1) {
    POST_STACK[++post_index] = stack_pop();
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

  printf("Post stack: ");
  for(int i = 0; i < ARR_LEN(POST_STACK); i++) {
    printf("%c", POST_STACK[i]);
  }
  printf("\n");
}

void stack_push(char value) {
    if (tos < OP_STACK_SIZE - 1) {
	OP_STACK[++tos] = value;
    }
}

char stack_pop() {
  if(tos == -1) {
    return '\0';
  } else {
    return OP_STACK[tos--];
  }
}

char stack_display() {
  if(tos == -1) {
    return '\0';
  } else {
    return OP_STACK[tos];
  }
}
