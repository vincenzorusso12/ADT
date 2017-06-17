#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct node {
item value;
struct node *next;
};


struct c_list {
struct node *first;
int size;
};


int sizeList (list l)
{
	if(l == NULL)
	return -1;
	return l->size;
}


list newList(void)
{
	struct c_list *l;
	l = malloc (sizeof(struct c_list));
	if (l != NULL) {
	l->first = NULL;
	l->size = 0;
}
	return l;
	/* il programma client dovrà controllare
	che il risultato non sia NULL */
}


int emptyList(list l)
{
	if(l == NULL)
	{return -1;}
	return (l->size == 0);
}

item getItem(list l, int pos){
	if(l == NULL)
		{return NULLITEM;}
		/* avendo l->size non abbiamo bisogno di scorrere la lista
		per verificare la precondizione pos < sizeList(l)
		*/
	if (pos<0 || pos>=l->size)
		{return NULLITEM;} // precondizione non verificata
	struct node *temp = l->first; // temp è usato per scorrere la lista
	int i = 0;
	while (i < pos) { // finchè non si arriva al nodo in posizione pos
		i++;
		temp=temp->next; // temp !=NULL garantito da pos < l->size
	}

	return temp->value;
}

int posItem (list l, item val){
	if(l== NULL)
		{return -1;}
	int pos =0;
	int found =0;
	struct node *temp = l->first;
	// temp è usato per scorrere la lista
	while (temp!=NULL && !found){ // visita finalizzata
		if (eq(temp->value, val))
			{found =1;}
		// elemento trovato
			else {
			temp=temp->next;
		// continua ricerca nella lista
			pos++;
		}
	}
	// se è stato trovato viene restituita la posizione altrimenti -1

	if(!found)
		{pos = -1;}
	return pos;
}

int insertList (list l, int pos, item val)
{
	if(l == NULL)
	{return 0;}
	if (pos<0 || pos>l->size) // precondizione non soddisfatta
	{return 0;}
	struct node* tmp = insertNode(l->first, pos, val);
	if(tmp==NULL) // se l’inserimento è fallito
	{return 0;} // restituisce 0 e non modifica la lista

	// se l’inserimento è riuscito modifichiamo la lista
	l->first = tmp;
	l->size++;
	return 1;
}

/* la funzione insertNode restituisce NULL se non riesce ad
allocare memoria per il nuovo nodo da inserire*/
static struct node* insertNode (struct node* n, int pos, item val)
{
	if(pos == 0)
	// caso inserimento in testa
	return makeNode(val, n);
	// NB: se makeNode non ha allocato memoria restituirà NULL
	//caso in cui pos > 0
	int i = 0;
	struct node* prec = n;
		while (i < pos-1) {
		// scorro la lista fino a posizione pos - 1
		prec = prec->next;
		i++;
		}
	/* All’uscita prec punta all’elemento di posizione pos-1.
	Il controllo su prec != NULL nella condizione del while questa volta
	è inutile perché insertNode viene chiamata da insertList solo se la
	lista ha almeno pos elementi (la precondizione è soddisfatta)
	*/
	struct node *n1 = makeNode(val, prec->next); // creo nuovo nodo
	if(n1 == NULL)
		{return NULL;} // operazione di inserimento non riuscita
	
	prec->next = n1;
	return n;
	// operazione di inserimento riuscita
}

static struct node* makeNode(item val, struct node* nxt)
{
	struct node *nuovo = malloc (sizeof(struct node));
	if (nuovo != NULL) {
	nuovo->value = val;
	nuovo->next = nxt;
	
	}
	return nuovo;
}

int removeList (list l, int pos)
{
	if(l == NULL)
	{return 0;}
	
	if (pos<0 || pos>=l->size)
	{return 0;}
	// precondizione non soddisfatta
	
	l->first = removeNode(l->first, pos);
	l->size--;
	return 1;
}

static struct node* removeNode(struct node* n, int pos)
{
	struct node* prec;
	struct node* n1;
	// puntatore al nodo da eliminare
	if(pos == 0) {
	n1 = n;
	n = n->next;
	free(n1);
	}
	// eliminazione in posizione 0
	/* NB: in questo caso non serve controllare anche che n != NULL
	perché removeNode viene invocata da removeList solo se il
	numero di elementi nella lista è maggiore di pos (la precondizione
	è soddisfatta)*/
	else { // caso in cui pos > 0
	int i = 0;
	struct node*prec = n;
	while (i < pos-1) { // scorriamo la lista fino a posizione pos-1
	prec = prec->next;
	i++;
	}
	/* Alla fine del ciclo, prec->next punta al nodo da eliminare.
	Il controllo su prec != NULL nella condizione del while questa volta
	è inutile perché removeNode viene chiamata da removeList solo se la
	lista ha almeno pos elementi (la precondizione è soddisfatta)
	Per lo stesso motivo è soddisfatta anche prec->next != NULL */
	}
	n1 = prec->next;
	prec->next = n1->next;
	free(n1);
	return n;
}

list reverseList1(list l) {
	if(l == NULL)
	{return NULL;}
	list l1 = newList();
	struct node *temp = l->first;
	// creiamo la nuova lista di output
	// serve a scorrere la lista di input
	// si scorre la lista di input e si inseriscono in testa alla nuova lista
	while(temp!=NULL) {
	l1->first = makeNode(temp->value, l1->first);
	temp=temp->next;
	}
	// l1->first è NULL se l è vuota o se makeNode non ha allocato memoria
	if (l1->first!=NULL)
	{l1->size=l->size;}
	// se l1->first è NULL allora l1->size è 0 (quella inizializzata da newList)
	return l1;
	/* NB: per semplicità nel ciclo non si controlla se makeNode
	restituisce NULL */
}

int reverseList2(list l) {
	if(l == NULL)
	{return 0;}
	struct node *n = l->first;
	// serve a scorrere la lista
	struct node *prec = NULL; // puntatore e predecessore di n
	struct node *succ;
	// usato per salvare il successore di n
	// si scorre la lista di input e n->next viene posto uguale a prec
	while(n!=NULL) {
	succ = n->next; // salviamo il puntatore al successivo
	n->next = prec; // il successore di n diventa il suo predecessore
	prec = n;
	// avanziamo prec sulla lista
	n = succ;
	// avanziamo n sulla lista
	}
	/* all’uscita del ciclo prec punta all’ultimo nodo della lista di input
	che ora diventa il primo nodo della reversed list
	*/
	l->first = prec;
	return 1;
}

list cloneList (list l) {
	if(l == NULL)
	{return NULL;}
	if(emptyList(l))
	{return newList();}
	struct node *temp = l->first;

	// serve a scorrere la lista di input
	list l1 = newList();
	// creiamo la nuova lista di output
	l1->first = makeNode(temp->value, NULL); // creazione primo nodo
	struct node *temp1 = l1->first; // puntatore all’ultimo nodo di l1
	while(temp->next != NULL) { // si scorre la lista di input
	temp1->next = makeNode(temp->next->value, NULL);
	temp=temp->next;
	temp1 = temp1->next;
	}
	l1->size = l->size;
	return l1;
	
	// NB: per semplicità non si controlla se makeNode restituisce NULL
}

/* deleteList trasforma la lista di input in lista vuota,
cancellando la lista collegata di nodi
*/
int deleteList (list l) {
	if(l == NULL)
	{return 0;}
	struct node *temp = l->first;
	struct node *temp1;
	// serve a scorrere la lista di input
	// punta al nodo da eliminare
	while(temp!=NULL) { // scorre la lista per eliminare i nodi
	temp1 = temp;
	temp=temp->next;
	free(temp1);
	}
	
	l->first = NULL;
	l->size = 0;
	return 1;
}

int outputList (list l)
{
	if(l == NULL)
	{return 0;}
	int i =0;
	struct node * temp = l->first;
	while(temp != NULL) {
	printf("Elemento di posizione %d: ", i);
	output_item(temp->value);
	printf("\n");
	temp = temp->next;
	i++;
	}
	return 1;
}

list inputList (int n)
{
	if(n <= 0)
	{return newList();}
	item val;
	list l = newList();
	printf("Elemento di posizione 0: ");
	input_item(&val);
	l->first = makeNode(val, NULL); // inserimento primo elemento
	struct node *temp = l->first;
	// puntatore all’ultimo nodo di l
	for(int i = 1; i < n; i++) {
	printf("Elemento di posizione %d: ", i);
	input_item(&val);
	temp->next = makeNode(val, NULL);
	temp = temp->next;
	}
	l->size = n;
	return l;
} // NB: per semplicità non si controlla se makeNode restituisce NULL

void destroyList(list	*l)	{
	if(*l	!=	NULL)	{
	deleteList(*l);
	free(*l);
	*l	=	NULL;
	}
}

struct node *ordina(struct node *l)
{	
	struct node *l1,*prec,*temp;
	//passo base
	if (l==NULL||l->next==NULL)
	{
		return l;
	}
	//passo ricorsivo
	else l1=ordina(l->next);
	
	prec=l;
	temp=l1;
	
	while (temp!=NULL&&(l->value>temp->value))
	{
		prec=temp;
		temp=temp->next;
	}
	
	//ins in coda
	if (temp==NULL)
	{
		l->next=NULL;
		prec->next=l;
		return l1;
	}

	//in in testa
	
	else if (temp==l1)
	{
		l->next=l1;
		return l;
	}
	//ins nel mezzo
	else
	{
		l->next=temp;
		prec->next=l;
		return l1;
	}
}

