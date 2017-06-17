#include <stdio.h>
#include <stdlib.h>
#include "anagramma.h"


int main (void)
{
    int pass=0;
    
    char s1[50];
    char s2[50];
    
    scanf("%s",s1);
    scanf("%s",s2);
    
    pass=anagramma(s1,s2);
    
    if(pass==1)
    {
    printf("true\n");
    }
}
