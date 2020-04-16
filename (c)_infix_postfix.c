// Program to covert infix to postfix using stack operation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack
{
  int top;
  int length;
  char *arr;
}stack;

stack *init_stack(int size)
{
  stack *s = (stack *)malloc(sizeof(stack));
  s->top = -1;
  s->length = size;
  s->arr = (char *)malloc(sizeof(char)*size);
  return s;
}

int is_empty(stack *s)
{
  return s->top == -1;
}

int is_full(stack *s)
{
  return s->top == s->length-1;
}

char peek(stack *s)
{
  return s->arr[s->top];
}

void push(stack *s, char operand)
{
  if(!is_full(s))
  {
    s->arr[++(s->top)] = operand;
  }
  else
  {
    printf("\nError stack full. Initialize stack with more space.\n");
    exit(0);
  }
}

char pop(stack *s)
{
  if(!is_empty(s))
  {
    return s->arr[s->top--];
  }
  else
  {
    printf("\nError stack empty. Initialize stack with more space.\n");
    exit(0);
  }
  return '#';
}

// function to get the weight of an operatior
int weight(char operator)
{
  switch(operator)
  {
    // taking advantage of bleeding
    case '+':
    case '-':
             return 1;
    case '*':
    case '/':
             return 2;
    case '^':
             return 3;
  }
  return -1;
}

char *infix2postfix(char *expression)
{
  int j = 0, prev_weight, curr_weight;
  char popped;
  stack *s = init_stack(strlen(expression));
  char *postfix_exp = (char *)malloc(sizeof(char)*strlen(expression));
  for(int i=0; expression[i] != '\0'; i++)
  {
    if(isalnum(expression[i]))
    {
      postfix_exp[j++] = expression[i];
    }
    else
    {
      if(expression[i] == ')')
      {
        popped = pop(s);
        while(popped != '(')
        {
          postfix_exp[j++] = popped;
          popped = pop(s);
        }
      }
      else if(expression[i] == '(')
      {
        push(s, expression[i]);
      }
      else
      {
        prev_weight = weight(peek(s));
        curr_weight = weight(expression[i]);
        while(curr_weight <= prev_weight)
        {
          postfix_exp[j++] = pop(s);
          prev_weight = weight(peek(s));
        }
        push(s, expression[i]);
      }
    }
  }
  while(!is_empty(s))
  {
    postfix_exp[j++] = pop(s);
  }
  postfix_exp[j] = '\0';
  return postfix_exp;
}

int main()
{
  char exp[100];
  printf("Enter infix expression: ");
  scanf("%s", exp);
  printf("Postfix expression: ");
  printf("%s\n", infix2postfix(exp));
}
