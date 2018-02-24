#include<stdio.h>

int count(int n)
{
    int C[n + 1];
    int i;
	C[1] = 1;
	C[2] = 2;
    for(i = 3; i <= n; i++)
    {
            C[i] = C[i - 1] + C[i - 2];
    }
    return C[n];
}

int main()
{
    int n;
	scanf("%d", &n);
	printf("%d", count(n));
    return 0;
}
