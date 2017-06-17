#include <stdlib.h>
#include <stdio.h>
#include "merge.h"

int main()	
{
	 int i=0;int n1=0;int n2=0;
	
	 printf("\nEnter no of elements in 1st array :");
 	 scanf("%d", &n1);
 	 
 	 int *a=malloc(n1*sizeof(int));
 	 
	 for (i = 0; i < n1; i++) {
	 scanf("%d", &a[i]);
	 }
 
	 printf("\nEnter no of elements in 2nd array :");
	 scanf("%d", &n2);
	 
	 int *b=malloc(n2*sizeof(int));
	 
	 for (i = 0; i < n2; i++) {
	 scanf("%d", &b[i]);
	 }
 
	
	merge(a,b,n1,n2,n1+n2);
	
}	

