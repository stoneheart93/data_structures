#include<stdio.h>

int allSubarraySum(int a[], int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += (a[i] * (n - i) * (i + 1)); 
	return sum;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", allSubarraySum(a, n));
	return 0;
}
