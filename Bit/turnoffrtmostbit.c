#include<stdio.h>

int turn(int n)
{
    return n & (n - 1);
}    
int main()
{
    int n;
    scanf("%d", &n);
	printf("%d", turn(n));
    return 0;
}
