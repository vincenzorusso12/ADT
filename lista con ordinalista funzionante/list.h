#include"item.h"


typedef struct c_list *list;


list newList(void);
int emptyList(list l);
int sizeList (list l);
item getItem (list l, int pos);
int posItem (list l, item val);
int insertList(list l, int pos, item val);
int removeList(list l, int pos);
list reverseList1(list l); // restituisce la reverse in una nuova lista
int reverseList2(list l); // fa la reverse della lista di input
int deleteList(list l);
list cloneList(list l);

static struct node* makeNode(item val, struct node* nxt);
static struct node* removeNode(struct node* n, int pos);
static struct node* insertNode (struct node* n, int pos, item val);
void destroyList(list	*l);
list inputList (int n);
int outputList (list l);
struct node*ordina(struct node *l);
