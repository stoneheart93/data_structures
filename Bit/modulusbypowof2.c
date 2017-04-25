#include<stdio.h>

int getModulo(int n, int d)
{
	return (n & (d - 1));
}
int main()
{
	int n, d;
    scanf("%d%d", &n, &d);
    printf("Remainder: %d", getModulo(n, d));
    return 0;
}
