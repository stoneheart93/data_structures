#include<stdio.h>

int computeXOR(int n)
{
	int rem = n % 4;
	if(rem == 0)
		return n;
	else if(rem == 1)
		return 1;
	else if(rem == 2)
		return n + 1;
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", computeXOR(n));
	return 0;
}

/*
ip 
17
op 
1
*/
