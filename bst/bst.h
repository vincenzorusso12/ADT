#include "item.h"
/*
	SPECIFICA SINTATTICA
TIPI: BST, BOOLEAN, NODO, ITEM, VETTORE

OPERATORI:
CREABST:( ) → BST
ALBVUOTO:(BST) → BOOLEAN
RADICE:(BST) → NODO
FIGLIOSX:(BST) → BST
FIGLIODX:(BST) → BST
COSTRBINALB:(ITEM, BST, BST) → BST
K-BILANCIATO(BST,INT)→BOOLEAN
1-BILANCIATO(BST,VETTORE)→BST 1-BILANCIATO
STAMPAFOGLIEPERLIVELLI(BST)→()
ABS(INT)→INT
MAX(INT1,INT2)→INT(MASSIMO TRA INT1 e INT2)
ALTEZZA(BST)→INT
VISIT(BST)→()

	SPECIFICA SEMANTICA

ALBEROBST è un tipo di albero i cui nodi sono formati dalla tripla:(puntatore a figlio sx,puntatore a figlio dx, dato generico item) ed in cui ogni elemento del sottoalbero di sinistra precede la radice, ogni elemento del sottoalbero di destra segue la radice ed i sottoalberi sinistro e destro sono	alberi di ricerca binaria

Un albero di ricerca binaria si dice K-bilanciato se per ogni	nodo accade che la differenza (in valore assoluto) tra le altezze dei suoi due sottoalberi è minore o uguale a K

CREABST ( ) = T
pre:
post: T = ᴧ

ALBVUOTO (T) = v
pre:
post: se T è vuoto, allora v = vero, altrimenti v = falso

RADICE (T) = N’
pre: T = <N, Tsx, Tdx> non è l’albero vuoto
post: N = N’

FIGLIOSX (T) = T’
pre: T = <N, Tsx, Tdx> non è l’albero vuoto
post: T’ = Tsx

FIGLIODX (T) = T’
pre: T = <N, Tsx, Tdx> non è l’albero vuoto
post: T’ = Tdx

COSTRBST (elem, T1, T2) = T’
pre:
post: T’ = <N, T1, T2>
N è un nodo con etichetta elem

K-BILANCIATO(BST,INT)=BOOLEAN
pre:  k>=0  e <N, Tsx, Tdx> non è l’albero vuoto
post:	restituisce vero se l'albero T è k-bilanciato falso altrimenti

1-BILANCIATO(BST,VETTORE)=BST 1-BILANCIATO
pre:<N, Tsx, Tdx> non è l’albero vuoto e <a[1],a[2],...,a[n]> è un vettore con a[i]<a[j] se i<j (ordinato in maniera crescente)
post:T’ = <N, T1, T2> è un albero contenete gli elementi del vettore ed è 1-bilanciato

STAMPAFOGLIEPERLIVELLI(BST)=()
pre:<N, Tsx, Tdx> non è l’albero vuoto
post:siano stampati i nodi foglia in ordine di livello

ABS(INT)=INT
pre:sia a un intero
post:se a<0 restituisce -a altrimenti +a

MAX(INT1,INT2)=MAX(INT2,INT2)
pre:siano a,b interi
post:se a>=b restituisce a altrimenti restituisce b

ALTEZZA(BST)=INT
pre:<N, Tsx, Tdx> non è l’albero vuoto
post:restituisce 1+max(altezza(Tsx),altezza(Tdx))

VISIT(BST)→()
pre:<N, Tsx, Tdx> non è l’albero vuoto
post:
*/


typedef struct node *BST;


// prototipi
item getItem(struct node *N);
void setItem(struct node *N, item el);
BST newBST (void);
int emptyBST (BST T);
int contains(BST T, item val);
void insert(BST *T, item elem);
BST creaFoglia(item elem);
BST figlioSX(BST T);
BST figlioDX(BST T);
struct node * minValue(struct node* node);
struct node * maxValue(struct node* node);
struct node *search(struct node* x, item k);
BST consBST(item val, BST sx, BST dx);
BST inputBST(void);
int verifica(BST T,int min,int max);
int num_nodi(BST T);
int num_nodi_iter(struct node * T);
void stampa_decrescente(BST T);
void visit(BST T);
void n_nodi_grandi(BST T,int n);//stampa i grandi
void n_nodi_piccoli(BST T,int n);


int k_bilanciato(BST T, int k);


BST uno_bil (BST T, int *v, int i,int j);



void foglie_per_livelli(BST T);


int abs(int n);


int max(int a,int b);


int altezza(BST T);



void preorder(BST T);
void inorder (BST T);
void postorder (BST T);
void Visita_preorder_iter(struct node * T);
void Visita_inorder_iter(struct node * T);
void Visita_postorder_iter(struct node * T);
void stampa_livelli(BST T);

//void attraversa_pari(BST T,list l);
//void attraversa_dispari(BST T,list l);
