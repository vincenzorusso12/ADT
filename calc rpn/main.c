#include "calcolatrice.h"

int main ()
{	
	int i=0;
	double ris=0;
	char stringa[200];

	
	
	
	printf("inserisci stringa prima numeri e poi gli operatori\n");
	scanf("%s",stringa);
	printf("%s\n",stringa);
	
	ris=calcolaStack(stringa);
	printf("IL risultato è %lf  \n",ris);
	
	
	
	return 0;
}
