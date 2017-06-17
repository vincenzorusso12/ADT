#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
struct item
{
	char titolo[20];
	char cantante[20];
	int durata;
	

};



int item_cmp(item x,item y)
{
	return strcmp(x->titolo,y->titolo);

}

item new_item(char *titolo,char *cantante,int durata)
{
	item x;
	
	x = malloc(sizeof(struct item));
	if (x!=NULL)
	{
		strcpy(x->titolo, titolo);
		strcpy(x->cantante, cantante);
		x->durata=durata;
	}
	return x;	

}

item input_item()
{
	
	char titolo[20];
	char cantante[20];
	int durata;
	
	
	printf("inserisci titolo\n");
	scanf("%s",titolo);
	
	printf("inserisci cantante\n");
	scanf("%s",cantante);
	
	printf("inserisci durata\n");
	scanf("%d",&durata);
	
	return new_item(titolo,cantante,durata);

}

void output_item(item x)
{

	printf("titolo\n");
	printf("%s",x->titolo);
	
	printf("inserisci cantante\n");
	printf("%s",x->cantante);
	
	printf("inserisci durata\n");
	printf("%d",x->durata);
	


}

char * get_titolo(item x){
	return x->titolo;
}
