#include<stdio.h>

int isPowerOfTwo(int n)
{
    return (n && (! (n & (n - 1))) );
}

int firstLastSet(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 0;
    else
	    return isPowerOfTwo(n - 1);
}
 
int main()
{
	int num;
    scanf("%d", &num);
    if(firstLastSet(num))
    	printf("First and Last are set");
    else
    	printf("Not set");
    return 0;
}
