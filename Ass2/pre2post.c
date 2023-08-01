// prefix to postfix expression conversion using stack in c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *stack, int *top, char value) {
  stack[++(*top)] = value;

  return;
}

char pop(char *stack, int *top) { return stack[(*top)--]; }

int main() {
  char *stack = (char *)malloc(100 * sizeof(char));
  int top = -1;

  char *expression = (char *)malloc(100 * sizeof(char));
  printf("Enter the prefix expression: ");
  scanf("%s", expression);

  int length = strlen(expression);

  for (int i = length - 1; i >= 0; i--) {
    if (expression[i] >= '0' && expression[i] <= '9') {
      printf("%c", expression[i]);
    } else {
      push(stack, &top, expression[i]);
    }
  }

  while (top != -1) {
    printf("%c", pop(stack, &top));
  }

  printf("\n");

  return 0;
}
