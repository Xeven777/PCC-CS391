// postfix expression evaluation using stack in c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int *stack, int *top, int value) {
  stack[++(*top)] = value;

  return;
}

int pop(int *stack, int *top) { return stack[(*top)--]; }

int main() {
  int *stack = (int *)malloc(100 * sizeof(int));
  int top = -1;

  char *expression = (char *)malloc(100 * sizeof(char));
  printf("Enter the postfix expression: ");
  scanf("%s", expression);

  int length = strlen(expression);

  for (int i = 0; i < length; i++) {
    if (expression[i] >= '0' && expression[i] <= '9') {
      push(stack, &top, expression[i] - '0');
    } else {
      int operand1 = pop(stack, &top);
      int operand2 = pop(stack, &top);

      switch (expression[i]) {
      case '+':
        push(stack, &top, operand2 + operand1);
        break;

      case '-':
        push(stack, &top, operand2 - operand1);
        break;

      case '*':
        push(stack, &top, operand2 * operand1);
        break;

      case '/':
        push(stack, &top, operand2 / operand1);
        break;

      case '%':
        push(stack, &top, operand2 % operand1);
        break;

      default:
        printf("Invalid operator\n");
        break;
      }
    }
  }

  printf("Result: %d\n", pop(stack, &top));

  return 0;
}
