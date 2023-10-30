#include <stdio.h>

int gcdrecusive(int x, int y )
{
	printf("x:%d y:%d\n",x,y);
	int rem = y % x;
	if(rem == 0 )
	{
		return x;
	}
	
	printf("rem:%d \n",rem);
	return gcdrecusive(rem, x);
}

int gcd(int x, int y )
{
	int rem = y % x;
	while(rem != 0)
	{
		y = x;
		x = rem;
		rem = y % x;
	}
	
	return x;
}
void main()
{ 
  //printf("8-44 %d\n",gcd(44,8));
  printf("8-44 %d\n",gcdrecusive(8,44));
  //printf("5:10 %d\n",gcd(5,10));
  //printf("5:10 %d\n",gcd(10,15));
  
}

 