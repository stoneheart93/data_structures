#include<stdio.h>

int firstLastSet(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 0;
    return (((n - 1) & (n - 2)) == 0);
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
