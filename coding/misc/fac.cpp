#include <stdio.h>

int facrec(int i)
{
	if( i== 1)
	{
	  return 1;
	}

	return facrec(i-1)* i;
}

int fac(int i)
{
	int result = 1;
	for(int k=2; k<=i; k++)
	{
		result *= k;
	}
	
	return result;
}

void main()
{
	printf("%d\n",fac(5));
	printf("%d\n",facrec	(5));
	printf("%d\n",fac(6));
	printf("%d\n",facrec	(6));
	
}