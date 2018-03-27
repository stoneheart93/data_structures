#include<stdio.h>
 
void printNos(int n)
{
	if(n > 0)
	{
    	printNos(n-1);
    	printf("%d ", n);
	}
}
 
int main()
{
	printNos(100);
	return 0;
}
