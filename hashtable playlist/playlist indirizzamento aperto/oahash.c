#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemhash.h"
#include "oahash.h"
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

int HashInsert( struct hash *h, char *key, char *cantante,
int durata ) {


	int idx, start; int i = 0, len = h->size;
	start = idx = hash(key,h->size);
	do {
			if(h->table[idx] == NULL) { /* posto libero */
				h->table[idx]=new_item(key,cantante,durata);
				return (1);
			} else { /* prova successivo */
				i++;
				idx = hash(key,h->size);
			}
		} while (idx != start);
	return (0);
}


int DeleteHash(hashtable h, char *key) {
	int idx;
	struct item *prev, *curr, *head;
	idx = hash(key, h->size);
	prev = curr = head = h->table[idx];
	while(curr) {
		if( !strcmp(curr->key, key) ) {
			if(curr == head) h->table[idx] = curr->next;
			else prev->next = curr->next;
			return 1;
		}
		prev = curr;
		curr = curr->next;
	}
	return 0;
}


item HashSearch(struct hash *h, char *key) {
	int idx, start; int i = 0;
	start = idx = hash(key,h->size);
	do {
		if(h->table[idx] == NULL) { /* posto libero */
			return (NULL);
		} else
		if ( !strcmp(h->table[idx]->key, key) ) {
			return h->table[idx];
		} else {
			i++; idx = hash(key,h->size);
		}
	} while( idx != start );
	return (NULL);
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
