#include<stdio.h>

int findPieces(int n)
{
	return (n * (n + 1))/2 + 1;
}
 
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", findPieces(n));
    return 0;
}
