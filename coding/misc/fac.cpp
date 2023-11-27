#include <stdio.h>

/*
	curVal = 5
	  (4,5)
	  4*5 = 20
	 (3,20)
	 (2,60)
	 (1,120);

	A special form of recursion where the last operation of a function is a recursive call. The recursion may be optimized away by executing the call in the current stack frame and returning its result rather than creating a new stack frame.
*/
int facrecbyTail(int i, int curVal)
{
	if( i== 1)
	{
	  return curVal;
	}

	return facrecbyTail(i-1, curVal*i);
}


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
	printf("%d\n",facrecbyTail(5,1));

	printf("_______________\n");
	
	printf("%d\n",fac(6));
	printf("%d\n",facrec	(6));
	printf("%d\n",facrecbyTail(6,1));

	printf("_______________\n");
}