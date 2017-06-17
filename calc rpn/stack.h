#include"list.h"


typedef struct c_stack *stack;

int outputStack(stack s);
stack newStack(void);
int emptyStack(stack s);
int push(item val, stack s);
int pop (stack s);
item top (stack s);
