#include <stdio.h>
#include "quicksort.h"

int funzione(int a[],int n,int el)
{
	int i=0;
	int j=0;
	int k=n-1;
	int trovato=0;
	
	quicksort(a,0,n-1);
	
	while (j<=k&&!trovato)
	{
	
		if(a[j]+a[k]>el)
		{
		 k--;
		 }
		if(a[j]+a[k]<el)
		{
		 j++;
		 }
		
		if(a[j]+a[k]==el)
		{
		 trovato=1;
		 }

	}
	
		return trovato;

}

int main()
{
	int a[100];
	int n=0;
	int i=0;
	int el=0;
	
	printf("quanti elementi vuoi inserire \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("inserisci il numero che vuoi vedere se la sua somma è nell array \n");
	scanf("%d",&el);
	
	if(funzione(a,n,el))
	{
	printf("pass\n");
	}

}
