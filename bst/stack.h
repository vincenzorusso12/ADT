#include "stackitem.h"

// file stack.h
typedef struct c_stack *stack;
// prototipi
stack newStack(void);
int emptyStack(stack s);
int pop(stack s);
int push(puntatore val, stack s);
int calcolaStack(char str,stack stk );
puntatore top (stack s);
