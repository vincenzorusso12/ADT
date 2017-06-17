#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "ordina.h"
  
int main()
{
    int i=0;
    int a[50];
    int n=0;
    printf("inserisci quanti numer  vuoi mettere");
    scanf("%d",&n);
    printf("inserisci 0 oppure 1\n");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    
    ordina(a,n);
    
    for(i=0;i<n;i++)
    {
    printf("%d",a[i]);
    }
    
}

