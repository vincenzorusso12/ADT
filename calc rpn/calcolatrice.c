#include "calcolatrice.h"

double calcolaStack(char *str)
{
	char temp;
	stack stk=newStack();
	double a=0,b,c=0;int i=0;
	double ris=0;

	while ( (str[i])>='0' && (str[i])<='9')
	{
		temp=str[i];
		push(atof(&temp),stk);
		i++;
	
	}
		outputStack(stk);	
		ris = top(stk);pop(stk);
			while(str[i]!=';'&&str[i]!='\0')
	{
		printf("%c\n",str[i]);
		a=top(stk);pop(stk);
		
		if (str[i]=='+')
		{
			ris=a+ris;
		}
		
		if (str[i]=='-')
		{
			ris=a-ris;
		}
		
		if (str[i]=='*')
		{
			ris=a*ris;
		}
		
		if (str[i]=='/')
		{
			ris=a/ris;
		}
		i++;
	}
	
	return ris;

}


