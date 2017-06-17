#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemhash.h"
#include "chainhash.h"
#include "list.h"

struct hash {
int size;
struct item **table;
};


hashtable newHashtable(int size)
{
	int i;
	hashtable h = malloc(sizeof(struct hash));
	h->size = size;
	h->table = (struct item **) malloc (size*sizeof(struct item *));
	for(i=0; i<size; i++) {
	h->table[i] = NULL;
	}
	return h;
}

int InsertHash(hashtable h, struct item *elem) {

	if (elem==NULLITEMHASH)
		return -1;
		
	int idx;
	struct item *head, *curr;
	idx = hash(elem->key, h->size);
	curr = head = h->table[idx];
	

	while(curr) {
	if( strcmp(curr->key, elem->key)==0 )
	return (-1);
	curr = curr->next;
	}
	h->table[idx] = elem;
	h->table[idx]->next = head;
	return 1;
}


struct item* searchHash(hashtable h, char*key) {
	int idx;
	struct item *curr;
	idx = hash(key, h->size);
	curr = h->table[idx];
	while(curr) {
		if( strcmp(curr->key, key)==0 )
		return curr;
		
		curr = curr->next;
	}
	return NULLITEMHASH;
}



int DeleteHash(hashtable h, char *key) {
	int idx;
	struct item *prev, *curr, *head;
	idx = hash(key, h->size);
	prev = curr = head = h->table[idx];
	while(curr) {
		if( !strcmp(curr->key, key) ) 
			{
			if(curr == head) h->table[idx] = curr->next;
			else prev->next = curr->next;
			return 1;
			}
		prev = curr;
		curr = curr->next;
	}
	return 0;
}


void DestroyHash(hashtable h) {
int i;
for(i=0; i < h->size; i++) {
deleteList1(h->table[i]);//implementare a parte
}
free(h->table);
return;
}

int deleteList1 (list l) {
	if(l == NULL)
	{return 0;}
	struct item *temp = l;
	struct item *temp1;
	// serve a scorrere la lista di input
	// punta al nodo da eliminare
	while(temp!=NULL) { // scorre la lista per eliminare i nodi
	temp1 = temp;
	temp=temp->next;
	free(temp1);
	}
	
	
	return 1;
}

/*int outputList1(list l)
{
	if(l == NULL)
	{return 0;}
	int i =0;
	struct item * temp = l;
	while(temp != NULL) {
	printf("Elemento di posizione %d: ", i);
	output_item(temp);
	printf("\n");
	temp = temp->next;
	i++;
	}
	return 1;
}


void PrintHash(hashtable h,int size)
{
	int i=0;
	
	for(i=0;i<size;i++)
	{
		outputList1(h->table[i]);
	}
}
*/

static void deleteList(struct item *p) {
if (p == NULL) return;
deleteList1(p->next);//implementare a parte
free(p);
}

//fare funzione che stampa hash table
int hash(char *k, int m){
int val;
int len = strlen(k);

val = k[0] + k[len-1] + len;
return (val % m);

}
