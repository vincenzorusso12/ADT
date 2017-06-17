#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "bst.h"
#include "stack.h"
//#include "list.h"

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
N->value = el; // correttezza di =
}

// dipende dal tipo item

BST newBST (void)
{
return NULL;
}

int emptyBST (BST T)
{
return T == NULL;
}

item contains(BST T, item val)
{
if (T == NULL) return 0;
if ((item_cmp(val, getItem(T))==0))
	return T->value;
if ((item_cmp(val,getItem(T))<0))
	return (contains(figlioSX(T), val));
else
	return (contains(figlioDX(T), val));
}


void insert(BST *T, item elem)
{
if (*T==NULL) {*T= creaFoglia(elem);}
else if (item_cmp(elem ,getItem(*T))<0)
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
if (item_cmp(key,root->value)<0)
root->left = deleteNode(root->left, key);
else if (item_cmp(key,root->value)>0)
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
// Delete the inorder successor
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
	if (item_cmp(k,getItem(x))<0)
	return search(x->left,k);
	else return search(x->right,k);
}


void inorder (BST T)
{
if(T==NULL) return;
printf(" ");
inorder(T->left);
printf(" ");
visit(T);
printf(" ");
inorder(T->right);
}

void visit(BST T)
{
	return output_item(getItem(T));
}


/*
BST inputBST(int n)
{
	int i=0;
	
	BST sx,dx;
	item elem = new_item();
	input_item(elem);
	if(i<n);
	{
	sx=inputBST(n++);
	dx=inputBST(n++);
	}
	
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
// dipende dal tipo item
return nuovo;
}
*/
/*int verifica(BST T,int min,int max)//verifica che e un albero binario di ricerca
{
	if (T==NULL)
	{
		return 1;
	}

	if(getItem(T)<=min||getItem(T)>=max)
	{
		return 0;
	}
	
	return verifica(T->left,min,getItem(T)) && verifica(T->right,getItem(T),max);
}

int num_nodi(BST T)
{
	if (T==NULL)
	{
		return 0;
	}
	
	
	return 1+num_nodi(T->left)+num_nodi(T->right);

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
}item_cmpnputb


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
