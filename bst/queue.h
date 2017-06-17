#include"itemqueue.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
int enqueue(puntqueue val, queue q);
puntqueue dequeue(queue q);
