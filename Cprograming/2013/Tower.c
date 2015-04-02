#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack
{
  int top;
  char elements[100];
}
Stack;

void init_stack(Stack *s)
{
  s->top = 0;
}

int stack_full(Stack *s)
{
  return(s->top >= 100);
}

int stack_empty(Stack *s)
{
  return(s->top <= 0);
}

void push_stack(Stack *s, char i)
{
  if (stack_full(s)) return;
  s->elements[s->top] = i;
  s->top++;
}

int pop_stack(Stack *s)
{
  if (stack_empty(s)) return(-1);
  s->top--;
  return(s->elements[s->top]);
}

void print_stack(Stack *s)
{
  int i;
  for (i = 0; i < s->top; i++) putchar(s->elements[i]);
  putchar('\n');
}

void hanoi(int n,Stack s[3],int buffer,int src,int dst)
{
  if (n == 1)
  {
    push_stack(&s[dst],pop_stack(&s[src]));
    printf("==========\n");
    print_stack(&s[1]);
    print_stack(&s[0]);
    print_stack(&s[2]);
  }
  else
  {
    hanoi(n - 1, s, dst, src, buffer);
    push_stack(&s[dst],pop_stack(&s[src]));
    printf("==========\n");
    print_stack(&s[1]);
    print_stack(&s[0]);
    print_stack(&s[2]);
    hanoi(n - 1, s, src, buffer, dst);
  }
}

int main(void)
{
  Stack s[3];
  init_stack(&s[0]);
  init_stack(&s[1]);
  init_stack(&s[2]);
  scanf("%s", s[1].elements);
  s[1].top=strlen(s[1].elements);
  hanoi(s[1].top,s,0,1,2);
  return 0;
}
