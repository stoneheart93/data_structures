#include<stdio.h>

int count(int n)
{
    int C[n + 1];
    int i;
    C[1] = 1;
	C[2] = 2;
    C[3] = 4;
	for(i = 4; i <= n; i++)
        C[i] = C[i - 1] + C[i - 2] + C[i - 3];
    return C[n];
}

int main()
{
    int n;
	scanf("%d", &n);
	printf("%d", count(n));
    return 0;
}
