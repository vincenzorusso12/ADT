#include <stdio.h>
#include <stdlib.h>
#include "itemqueue.h"
#include "queue.h"

struct node {
puntqueue value;
struct node *next;
};

struct c_queue {
struct node *head,*tail;
int numel;
};

queue newQueue(void)
{
	struct c_queue *q;
	q = malloc (sizeof(struct c_queue));
	if (q == NULL)
		return NULL;
	q->numel = 0;
	q->head = NULL;
	q->tail = NULL;
	return q;
}

int emptyQueue(queue q)
{
	if (q==NULL)
		return -1;
	return q->numel == 0;
}

int enqueue(puntqueue val, queue q)
{
	if (q==NULL)
		return -1;
	
	struct node *nuovo;
	nuovo = malloc (sizeof(struct node));
	if (nuovo == NULL)
		return 0;
	nuovo->value = val;
	
	
	if(q->head==NULL)
		q->head = nuovo;
	else
		q->tail->next= nuovo; //inserimento in coda

	q->tail = nuovo;
	(q->numel)++;
	return 1;
}

puntqueue dequeue(queue q)
{
	if (q==NULL)
		return NULLQUEUE;
	if (q->numel == 0)
		return NULLQUEUE;
	puntqueue result;
	struct node *temp;
	temp = q->head;
	result = temp->value;
	q->head = q->head->next;
	if(q->head==NULL)
		q->tail=NULL;
	free(temp);
	(q->numel)--;
	
	return result;
}
