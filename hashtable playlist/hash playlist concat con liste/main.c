#include <stdio.h>
#include "list.h"
#include "itemhash.h"
#include "chainhash.h"

void menu()
{
printf("Menu: (inserire 0 per uscire)\n");
printf("1. Inserimento canzone in hashtable\n");
printf("2. Rimozione canzone in hashtable\n");
printf("3. Ricerca e stampa canzone in hashtable\n");
}

int main()
{
	int n=0;
	hashtable h=newHashtable(10);
	menu();
	scanf("%d",&n);
	
	while (n!=0)
	{
		switch(n)
		{
			case 1:
				printf("Inserire canzone:\n\n");
				
				item a=input_item();
				printf("\n");


				int ris1=InsertHash(h,a);
				
				if (ris1==1)
				{
					printf("Canzone inserita correttamente\n\n");
				}
				
				else
				{
					printf("Impossibile inserire canzone\n\n");
				}
				
			
			break;
			
			case 2:
			
			printf("Inserire titolo canzone da rimuovere:\n\n");
				char key1[20];
				scanf("%s",key1);
				printf("\n");


				int ris2=DeleteHash(h,key1);
				
				if (ris2)
				{
					printf("Canzone rimossa correttamente\n\n");
				}
				
				else
				{
					printf("Impossibile rimuovere canzone\n\n");
				}
				
			
			
			
			break;
		
			case 3:
			printf("Inserire titolo canzone da cercare:\n\n");
				char key2[20];
				scanf("%s",key2);
				printf("\n");


				item b=searchHash(h,key2);
				
				if (b!=NULLITEMHASH)
				{
					printf("Canzone trovata\n\n");
					output_item(b);
					printf("\n\n");
				}
				
				else
				{
					printf("Canzone non trovata\n\n");
				}
				
			
			break;
		
			default:
				printf("Input non valido\n\n");
		}
		printf("Inserire nuovo comando\n");
		scanf("%d",&n);
	}
	

	
	
	
	



}
