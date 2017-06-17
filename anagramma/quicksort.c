int partition (char A[], int p, int r)
   {
    int x, i, j, temp;
    x = A[p];
    i=p-1;
    j=r+1;
    while (i < j){
    while(A[--j] > x);
    while(A[++i] < x);
    if(i<j){
    temp = A[i]; A[i]= A[j]; A[j] = temp;
    }
    }
    return(j);
    }

void quicksort(char A[], int p, int r)
{
    int q;
    if(p < r)
    {
    q = partition(A, p, r);
    quicksort(A, p, q);
    quicksort(A, q+1, r);
}
}

