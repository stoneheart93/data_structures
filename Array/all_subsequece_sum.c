#include<stdio.h>

int allSubsequenceSum(int a[], int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += a[i]; 
	return sum * (1 << (n - 1));
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", allSubsequenceSum(a, n));
	return 0;
}
