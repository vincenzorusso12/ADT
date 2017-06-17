#include "list.h"

typedef struct hash* hashtable;

hashtable newHashtable(int size);
int HashInsert( struct hash *h, char *key, char *cantante,
int durata );
int DeleteHash(hashtable h, char *key);
void DestroyHash(hashtable h);
int deleteList1 (list l);
int outputList1(list l);
static void deleteList(struct item *p);
item HashSearch(struct hash *h, char *key);
int hash(char *k, int m);
