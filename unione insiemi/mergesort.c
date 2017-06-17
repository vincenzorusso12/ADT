void MergeSort(int A[], int p, int r) 
{
	int q;
	if (p < r) 
	{
		q = (p + r)/2;
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
	}
}

void Merge(int A[], int p, int q, int r)
{
	int B[MAX], i, j, k;
	for (i=p, j=q+1, k=p; i<=q && j<=r; )
	if ( A[i] < A[j] )
	B[k++] = A[i++];
	else B[k++] = A[j++];
	for ( ; i<=q; ) B[k++] = A[i++];
	for ( ; j<=r; ) B[k++] = A[j++];
	for ( k=p; k<=r; k++) A[k] = B[k];
}