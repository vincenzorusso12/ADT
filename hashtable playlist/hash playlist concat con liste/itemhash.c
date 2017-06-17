#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemhash.h"


item new_item(char key[20],char cantante[20],int durata)
{
	struct item *nuovo;
	nuovo=malloc(sizeof(struct item));
	
	if (nuovo!=NULL)
	{
		strcpy(nuovo->key,key);
		strcpy(nuovo->cantante,cantante);
		nuovo->durata=durata;
	}
	return nuovo;
}

item input_item(void)
{
	char key[20];
	char cantante[20];
	int durata;

	printf("Inserisci titolo canzone\n");
	scanf("%s",key);
	
	printf("Inserisci cantante\n");
	scanf("%s",cantante);
	
	printf("Inserisci durata\n");
	scanf("%d",&durata);
	
	if(durata>=0)
		return new_item(key,cantante,durata);
	else
		return NULLITEMHASH;
}

void output_item(item x)
{
	char key[20];
	char cantante[20];
	int durata;


	printf("Titolo: ");
	printf("%s",x->key);
	printf("\n\n");
	
	printf("Cantante: ");
	printf("%s",x->cantante);
	printf("\n\n");
	
	printf("Durata: ");
	printf("%d",x->durata);
	printf("\n\n");
}
