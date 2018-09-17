#include<stdio.h>

int max(int a, int b)
{
	return (a > b)? a : b;
}
int maxLoot(int a[], int n)
{
    int C[n];
    int i;
    
    C[0] = a[0];
    C[1] = max(C[0], C[1]);
    
	for(i = 2; i < n; i++)
        C[i] = max(a[i] + C[i - 2], //include
			   C[i - 1]); //exclude
    return C[n - 1];
}

int main()
{
	int a[100];
    int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", maxLoot(a, n));
    return 0;
}
