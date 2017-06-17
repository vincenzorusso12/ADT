#include <stdio.h>
#include <stdlib.h>
void merge(int A[],int B[], int na, int nb, int maxsize)
{
 	int *C=malloc(maxsize*sizeof(int));
	int i, j, k, x;
	
	for (i=0, j=0, k=0; i<=na-1 && j<=nb-1; )
	{
		printf("%d --- %d\n",A[i],B[j]);
		if ( A[i] < B[j] )
			{C[k++] = A[i++];}
		else if (A[i] > B[j])
			{C[k++] = B[j++];}
		else 
		{
			C[k++]=A[i++];
			j++;
		}
	}
	
	for ( ; i<=na-1; ) C[k++] = A[i++];

	for ( ; j<=nb-1; ) C[k++] = B[j++];

	C=realloc(C,k*sizeof(int));	

	for ( x=0; x<=k-1; x++)
	{
		printf("%d",C[x]);
	}
	

}
