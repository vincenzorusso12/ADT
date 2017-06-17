#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "stack.h"

struct c_stack {
	list top;
};

stack newStack(void)
{
	struct c_stack *s;
	s = malloc (sizeof(struct c_stack));
	if (s == NULL)
	return NULL;
	s->top = newList();
	return s;
}

int outputStack(stack s)
{
	return outputList (s->top);
}
int emptyStack(stack s)
{
	return emptyList(s->top);
}
int push(item val, stack s)
{
	return insertList(s->top, 0, val);
}
int pop (stack s)
{
	return removeList(s->top,0);
}
item top (stack s)
{
	return getItem(s->top,0);
	
}
