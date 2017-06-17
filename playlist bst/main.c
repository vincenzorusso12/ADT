#include <stdio.h>
#include "bst.h"
/*
struct node {
item value;
struct node *left;
struct node *right;
};
*/

void scelte()
{
	printf("Menu:\n");
	printf("1.inserisci canzone\n");
	printf("2.rimuovi canzone\n");
	printf("3.cerca canzone\n");
	printf("4.stampa canzone\n");
}

int main()
{
	char titolo[20];
	item a;item stamp;
	
	BST T=newBST();
	BST found=newBST();
	
	
	int n=0;
	
	scelte();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:
				a=input_item();
				insert(&T,a);
				break;
		
			case 2:
				scanf("%s",titolo);
				a=new_item(titolo,"","");
				T=deleteNode(T,a);
				break;
		
			case 3:
				printf("Inserire titolo canzone da cercare\n");
				scanf("%s",titolo);
				a=new_item(titolo,"","");
				a = contains(T,a);
				if(a == NULL)			
					printf("Elemento non trovato\n");
				else
				{
					printf("Elemento trovato ed è il seguente:\n")
				output_item(a);
				}
				break;
				/*if(contains(T,a))
					printf("Trovato\n");
				else
					printf("Non trovato\n");	
				*/
				break;
		
			case 4:

				scanf("%s",titolo);
				a=new_item(titolo,"","");
				if(contains(T,a))
				//	printf("trovato"\;
				//output_item(found);
				
				
			break;
			
			default:
				printf("Scelta errata\n\n");
				scelte();
		}
		printf("? ");
		scanf("%d",&n);
	}
	
	//struct node*elem=newBST();
	
	//printf("\ninserire albero\n");
	//printf("quante canzoni vuoi\n");
	//scanf("%d",&num);

	
	//printf("ins n\n");
	
	//scanf("%d",&n);
	
	/*int isbin=verifica(T,0,100);
	if (isbin==0)
	{
		printf("albero non valido\n");
	}
	*/
	
	/*printf("dammi l'item da cercare");
	input_item(a);
	
	

	elem=search(T,a);
	
	if (elem!=NULL)
	{
	output_item(elem->value);
	}
	
	else {printf("non trovato");}
	*/
	//int num=num_nodi_iter(T);
	
	//printf("num nodi %d\n",num);
	/*printf("\n nodi piccoli \n");
	n_nodi_piccoli(T,n);
	
	printf("\n n nodi grandi \n");
	n_nodi_grandi(T,n);
	
	printf("\n max val ");
	struct node *max=maxValue(T);
	
	printf(" ");
	visit(max);	
	printf("\n");
	*/
	

}
