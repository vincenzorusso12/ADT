#include<stdio.h>
#include"list.h"
#include"item.h"

struct node {
item value;
struct node *next;
};


struct c_list {
struct node *first;
int size;
};

int main(void)
{
	list l=newList();
	int n=0;

	scanf("%d",&n);

	l=inputList(n);
	l->first=ordina(l->first);
	printf("\nlista ordinata\n");
	outputList(l);

	return 0;
}
