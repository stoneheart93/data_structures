#include<stdio.h>

int count(int n)
{
    int C[n + 1];
    int i;
    C[1] = 1;
	C[2] = 1;
	C[3] = 2;
	C[4] = 4;
    for(i = 5; i <= n; i++)
        C[i] = C[i - 1] + C[i - 3] + C[i - 4];
    return C[n];
}

int main()
{
    int n;
	scanf("%d", &n);
	printf("%d", count(n));
    return 0;
}
