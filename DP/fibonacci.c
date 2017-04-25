#include<stdio.h>

int fib(int n)
{
    int F[n + 1];
    int i;
	F[0] = 0;
	F[1] = 1;
    for(i = 2; i <= n; i++)
    {
            F[i] = F[i - 1]+ F[i - 2];
    }
    return F[n];
}

int main()
{
    int n;
	scanf("%d", &n);
	printf("%d", fib(n));
    return 0;
}
