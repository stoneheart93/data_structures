#include <stdio.h>
 
int sumProduct(int a[], int n)
{
	int i, res = 0;
	int sum[n];
	
	sum[n - 1] = a[n - 1];
	for(i = n - 2; i >= 0; i--)
	{
		sum[i] = sum[i + 1] + a[i];
	}
	
	for(i = 0; i < n - 1; i++)
	{
		res += a[i] * sum[i + 1]; 
	}
	return res;
}   
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", sumProduct(a, n));
	return 0;
}

