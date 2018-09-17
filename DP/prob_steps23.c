#include<stdio.h>

int count(int n, float p)
{
    double C[n + 1];
    int i;
    C[1] = 0;
	C[2] = p;
    C[3] = 1 - p;
	for(i = 4; i <= n; i++)
        C[i] = p * C[i - 2] + (1-p) * C[i - 3];
    return C[n];
}

int main()
{
    int n, p;
	scanf("%d", &n);
	scanf("%f", &p);
	printf("%f", count(n, p));
    return 0;
}
