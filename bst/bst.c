#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"
#include "stack.h"
#include "queue.h"

struct node {
	item value;
	struct node *left;
	struct node *right;
};


item getItem(struct node *N)
{
	if (N == NULL) return NULLITEM;
		return N->value;
}

void setItem(struct node *N, item el)
{
	if (N==NULL) return;
		N->value = el; 
}



BST newBST (void)
{
	return NULL;
}

int emptyBST (BST T)
{
	return T == NULL;
}

int contains(BST T, item val)
{
	if (T == NULL) return 0;
	if (eq(val, getItem(T)))
		 return 1;
	if ((val < getItem(T)))

		return (contains(figlioSX(T), val));

	else

		return (contains(figlioDX(T), val));
}

void insert(BST *T, item elem)
{
	if (*T==NULL) *T= creaFoglia(elem);
	else if (elem < getItem(*T))
		insert(&((*T)->left), elem);
	else
		insert(&((*T)->right), elem);
}

BST creaFoglia(item elem)
{
	struct node *N;
	N = malloc (sizeof(struct node));
	if (N == NULL) return NULL;
	setItem (N, elem);
	N -> left = NULL;
	N -> right = NULL;
	return N;
}

struct node* deleteNode(struct node* root, item key)
{
	if (root == NULL) return root;
	if (key < root->value)
		root->left = deleteNode(root->left, key);
	else if (key > root->value)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
		struct node *temp = root->right;
		free(root);
		return temp;
		}
		else if (root->right == NULL)
		{
		struct node *temp = root->left;
		free(root);
		return temp;
		}
		struct node* temp = minValue(root->right);
		root->value = temp->value;
		root->right = deleteNode(root->right, temp->value);
		}
	return root;
}


struct node * minValue(struct node* node)
{
	struct node* current = node;
	while (current->left != NULL)
	current = current->left;
	return current;
}

BST figlioSX(BST T)
{
	return T->left;
}

BST figlioDX(BST T)
{
	return T->right;
}

struct node *search(struct node* x, item k)
{
	if (x==NULL)
	{
		return x;
	}

	if (x == NULL || k == getItem(x))
		return x;
	if (k < getItem(x))
		return search(x->left,k);
	else 
		return search(x->right,k);
}

BST inputBST(void)
{
	BST sx,dx;
	item elem;
	input_item(&elem);
	if(eq(elem,NULLITEM)) return NULL;
	sx=inputBST();
	dx=inputBST();
	return consBST(elem,sx,dx);
}

BST consBST(item val, BST sx, BST dx)
{
	struct node *nuovo;
	nuovo = malloc (sizeof(struct node));
	if (nuovo != NULL) {
		setItem(nuovo, val);
		nuovo->left = sx;
		nuovo->right = dx;
}

return nuovo;
}

int verifica(BST T,int min,int max)//verifica che e un albero binario di ricerca
{
	if (T==NULL)
	{
		return 1;
	}

	if(getItem(T)<=min||getItem(T)>=max)
	{
		return 0;
	}
	
	return verifica(figlioSX(T),min,getItem(T)) && verifica(figlioDX(T),getItem(T),max);
}

int num_nodi(BST T)
{
	if (T==NULL)
	{
		return 0;
	}
	
	
	return 1+num_nodi(figlioSX(T))+num_nodi(figlioDX(T));

}

int num_nodi_iter(struct node * T) {
	
	stack st = newStack();
	struct node *curr = T;
	push(T,st);
	int i=0;
	
	while(!emptyStack(st)) {
	
	curr=top(st);
	pop(st);
	i++;
	if (curr->right != NULL)
		{push(curr->right,st);
	
		}
	
	if (curr->left != NULL)
		{push(curr->left,st);
		
		}
	}
	return i;
}


void visit(BST T)
{
	return output_item(getItem(T));
}


void stampa_decrescente(BST T)
{

	if(T==NULL) return;
	printf(" ");
	stampa_decrescente(T->right);

	printf(" ");
	visit(T);


	printf(" ");
	stampa_decrescente(T->left);


}

void n_nodi_grandi(BST T,int n)
{
	int i=0;

	if(T==NULL) return;
	printf(" ");
	
	if(i<n)
	{
	n_nodi_grandi(T->left,i++);
	printf(" ");
	n_nodi_grandi(T->right,i++);
	printf(" ");
	visit(T);
	}
}

void n_nodi_piccoli(BST T,int n)
{
	int i=0;

	if(T==NULL) return;
	printf(" ");
	
	if(i<n)
	{
	n_nodi_piccoli(T->right,i++);
	printf(" ");
	n_nodi_piccoli(T->left,i++);
	printf(" ");
	visit(T);
	}
}

struct node * maxValue(struct node* node)
{
	struct node* current = node;
	while (current->right != NULL)
	current = current->right;
	return current;
}

int k_bilanciato(BST T, int k)
{	
	int hdx=0;
	int hsx=0;
	int diff=0;
	
	//Caso base: un albero vuoto è k-bilanciato
	
	if(T==NULL)
		return 1;
		
	hsx=altezza(figlioSX(T));
	hdx=altezza(figlioDX(T));
	diff=hsx-hdx;
	//Passo ricorsivo: Se l'altezza in valore assoluto del sottoalbero dx e del sottolabero sx sono <= di k e i sottoalberi dx e sx sono k bilanciati allora l'albero T è k-bilanciato
	
	return abs(diff)<=k && k_bilanciato(figlioSX(T),k) && k_bilanciato(figlioDX(T),k);
		
}

BST uno_bil (BST T, int *v, int i,int j)
{
	//Caso base:i puntatori si sono oltrepassati a vicenda, non posso più dividere l'array a metà
	if (i>j)
	{
		return NULL;
	}

	int half=(i+j)/2;	//inserisco l'elemento al centro dell'array come radice
	
	insert(&T,v[half]);
	
	//Passo ricorsivo:Se figlio sx e dx sono alberi 1-bilanciati allora T è un albero 1-bilanciato
	T->left=uno_bil(figlioSX(T),v,i,half-1);
	T->right=uno_bil(figlioDX(T),v,half+1,j);
	
	return T;
	
}	

void foglie_per_livelli(BST T)
{
	queue q=newQueue();

	BST temp=newBST();
	
	if (!emptyBST(T))
	{
		enqueue(T,q);
	}
	
	while(!emptyQueue(q))
	{
		temp=dequeue(q);
		
		if((figlioSX(temp))==NULL && (figlioDX(temp))==NULL)//Se un nodo non ha figlio sx e dx è una foglia e lo stampo
			visit(temp);
		
		if(figlioSX(temp) != NULL)
		 	enqueue(temp->left,q);
		if(figlioDX(temp) != NULL)
			enqueue(temp->right,q);	
	}

}

int abs(int n)
{
	if (n<0)
		return -n;
	else 
		return n;
}

int max(int a,int b)
{
	if (a>=b)
		return a;
	else
		return b;

}

int altezza(BST T)
{
	if (T==NULL)//Caso base:l'albero vuoto ha altezza 0
		return 0;
	else
	//Passo ricorsivo:se altezza figlio sx e altezza figlio dx sono le altezze dei sottalberi di T allora l'altezza di T sara 1 + il massimo tra le altezze dei suoi sottoalberi
		return 1+max(altezza(figlioSX(T)),altezza(figlioDX(T)));
	
}

void preorder(BST T)
{
	if(T==NULL) return;
	printf(" ");
	visit(T);
	printf(" ");
	preorder(figlioSX(T));
	printf(" ");
	preorder(figlioDX(T));
}

void inorder (BST T)
{
	if(T==NULL) return;
	printf(" ");
	inorder(figlioSX(T));
	printf(" ");
	visit(T);
	printf(" ");
	inorder(figlioDX(T));
}

void postorder (BST T)
{
	if(T==NULL) return;
	printf(" ");
	postorder(figlioSX(T));
	printf(" ");
	postorder(figlioDX(T));
	printf(" ");
	visit(T);
}

void Visita_preorder_iter(struct node * T) {
	stack st = newStack();
	struct node *curr = T;
	push(T,st);
	
	while(!emptyStack(st)) {
	
	curr=top(st);
	pop(st);
	visit(curr);
	if (curr->right != NULL)
		push(curr->right,st);
	if (curr->left != NULL)
		push(curr->left,st);
	
	}
	
}

void Visita_inorder_iter(struct node * T) {
	stack st = newStack();
	struct node *curr = T;
	//push(T,st);
	
	while(!emptyStack(st) || curr!=NULL) {
	
	if(curr!=NULL)
	{
		push(curr,st);
		curr=curr->left;
	}
	
	else 
	{
		curr =top(st);
		pop(st);
		visit(curr);
		curr=curr->right;
	}
	
	}
}

void Visita_postorder_iter(struct node * T) {
	stack st =newStack();
	struct node *last;
	struct node *curr=T;
			push(curr,st);
	while(!emptyStack(st) || curr!=NULL)
	{
	if(curr!=NULL) {
		/* Discesa a sx */
		push(curr,st);
		curr = curr->left;
	}
	else {
		/* Visita o discesa a dx */
		curr = top(st);
		pop(st);
	
	if (!curr->right || last == curr->right)
	{
		visit(curr);
		last = curr;
		pop(st);
		curr = NULL;
		}
		else curr = curr->right; /* Discesa a dx */
	}
	}
}

void stampa_livelli(BST T)
{
	queue q=newQueue();

	BST temp=newBST();
	
	if (!emptyBST(T))
	{
		enqueue(T,q);
	}
	
	while(!emptyQueue(q))
	{
		temp=dequeue(q);
		visit(temp);
		
		if(temp->left != NULL)
		 	enqueue(temp->left,q);
		if(temp->right != NULL)
			enqueue(temp->right,q);	
	}

}

/*void attraversa_pari(BST *T,list **l)
{
	
	if (T==NULL)
	{
		return -1;
	}

	insertList(l,0,T);
	
	attraversa_dispari(T->left,l);
	attraversa_dispari(T->right,l);

}

void attraversa_dispari(BST *T,list **l)
{

	if (T==NULL)
	{
		return -1;
	}


	attraversa_pari(T->left,l);
	attraversa_pari(T->right,l);
}
*/
