#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void menu()
{
	printf("Menu: (Inserire 0 per uscire)\n");
	printf("1.Test BST k-bilanciato\n");
	printf("2.Test costruzione BST 1-bilanciato\n");
	printf("3.Test stampa elementi nodi foglia ordinati per livelli \n");
	/*printf("");
	printf("");*/
}


int main()
{

	int n=0;

	
	menu();
	
	
	scanf("%d",&n);
	
	while (n!=0)
	{
		switch(n)
		{
			case 1:
				printf("Inserimento albero BST, inserire 0 per avere un ramo vuoto\n");
				BST T1=newBST();
				T1=inputBST();
				
				if (!verifica(T1,-1000,1000))
				{
					printf("L'albero inserito non è un BST\n");
					break;
				}
				
				int k=0;int ris=0;
				printf("Inserire valore di k\n");
				scanf("%d",&k);
				
				ris=k_bilanciato(T1,k);

				if (ris)
				{
					printf("il BST è k-bilanciato\n");
				}
				else
				{
					printf("il BST non è k-bilanciato\n");
				}
				
				break;
				
			case 2:
				

				
				
				printf("Inserire numero elementi vettore\n");
				BST T2=newBST();
				int numel;
				scanf("%d",&numel);
				int *v=malloc(numel*sizeof(int));
				
				if(v==NULL)
				{
					return -1;
				  }
				  
				printf("Inserire elementi nel vettore\n");
				int i;
				for(i=0;i<numel;i++)
				{
					scanf("%d",&v[i]);
				}
				
				T2=uno_bil(T2,v,0,numel-1);
				
				int ris2=k_bilanciato(T2,1);
				
				if (ris2)
				{
					printf("il BST è 1-bilanciato\n");
				}
				else
				{
					printf("il BST non è 1-bilanciato\n");
				}
				
				inorder(T2);
				
				
				
				break;
			
			case 3:
				printf("Inserimento albero BST, inserire 0 per avere un ramo vuoto\n");
				BST T3=newBST();
				T3=inputBST();
				
				if (!verifica(T3,-1000,1000))
				{
					printf("L'albero inserito non è un BST\n");
					break;
				}
				
				foglie_per_livelli(T3);
				
				printf("\n");
			
				break;
				
			/*case 1:
				break;
		*/
			default:
				printf("Scelta non presente\n\n");
				menu();
		}
		printf("Inserire nuova scelta ");
		scanf("%d",&n);	
	
	}


}
