#include <string.h>
#include "quicksort.h"

int anagramma(char *s1, char *s2)
{
    int size1=strlen(s1);
    int size2=strlen(s2);
    if(size1!=size2)
        return 0;
    quicksort(s1,0,size1-1);
    quicksort(s2,0,size2-1);
    
    if(strcmp(s1,s2)==0)
    {
        return 1;
    }
    return 0;
   
}


