#include "list.h"

typedef struct hash* hashtable;

hashtable newHashtable(int size);
int InsertHash(hashtable h, struct item *elem);
int DeleteHash(hashtable h, char *key);
void DestroyHash(hashtable h);
int deleteList1 (list l);
int outputList1(list l);
static void deleteList(struct item *p);
struct item* searchHash(hashtable h, char*key);
int hash(char *k, int m);
