#include "item.h"


// file BST.h
typedef struct node *BST;
// prototipi
item getItem(struct node *N);
void setItem(struct node *N, item el);
BST newBST (void);
int emptyBST (BST T);
item contains(BST T, item val);
void insert(BST *T, item elem);
BST creaFoglia(item elem);
BST figlioSX(BST T);
BST figlioDX(BST T);

struct node * maxValue(struct node* node);
struct node *search(struct node* x, item k);
BST consBST(item val, BST sx, BST dx);
BST inputBST(int n);
void inorder (BST T);
struct node* deleteNode(struct node* root, item key);
struct node * minValue(struct node* node);
void visit(BST T);
/*int verifica(BST T,int min,int max);
int num_nodi(BST T);
int num_nodi_iter(struct node * T);
void stampa_decrescente(BST T);
void visit(BST T);
void n_nodi_grandi(BST T,int n);//stampa i grandi
void n_nodi_piccoli(BST T,int n);*/
//void attraversa_pari(BST T,list l);
//void attraversa_dispari(BST T,list l);
