#include <stdio.h>
#include <string.h>

#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])

#define MAX_ASCII 128
int PRECEDENCE_TABLE[MAX_ASCII] = {0};

#define PRE_STACK_SIZE 20
#define OP_STACK_SIZE 20
char PRE_STACK[PRE_STACK_SIZE];
int pre_index = -1;
char OP_STACK[OP_STACK_SIZE];
int tos = -1;

void stack_push(char);
char stack_pop();
char stack_display();

void strrev (char *str) {
  int start = 0;
  int end = strlen(str) - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

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
#define PRECEDENCE(op) PRECEDENCE_TABLE[(int)op]

void prefix(char *expression, int expLength) {
  for(int i = 0; i < expLength; i++) {
    char c = expression[i];
    if (c >= 65 && c <= 90) {
      printf("Character: %c\n", c);
      PRE_STACK[++pre_index] = c;
    }
    else if (c == 41 ) {
      printf("Close Paranthesis\n");
      stack_push(c);
    }
    else if (c == 40 ) {
      printf("Open Paranthesis\n");
      while (tos != -1 && stack_display() != 41) {
        PRE_STACK[++pre_index] = stack_pop();
      }
      stack_pop();           // remove `)`
    }
    else if (c == 94 || c == 36 ||c == 47 ||c == 42 ||c == 43 ||c == 45) {
      printf("Arithmethics\n");
      while (tos != -1 && PRECEDENCE(stack_display()) >= PRECEDENCE(c) && stack_display() != '(') {
        PRE_STACK[++pre_index] = stack_pop();
      }
      stack_push(c);
    }
    else {
      printf("Invalid Character\n");
      return;
    }
  }

  while (tos != -1) {
    PRE_STACK[++pre_index] = stack_pop();
  }
}
int main() {
  char exp[40];

  initialize_precedence();
  printf("Enter the infix expression: ");
  scanf("%s", exp);
  size_t expLen = strlen(exp);
  strrev(exp);
  prefix(exp, expLen);

  printf("Prefix expression: ");
  for(int i = pre_index; i >= 0; i--) {
    printf("%c", PRE_STACK[i]);
  }
  printf("\n");
  printf("Programmed by Pierce Neupane\n");
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
