#include<stdio.h>
#include<limits.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int minSubarraySizeK(int a[], int n, int k)
{
	int curr_sum = 0;
	int i;
	
	for(i = 0; i < k; i++)
		curr_sum += a[i];
		
	int min_sum = curr_sum;
		
	for(i = k; i < n; i++)
	{
		curr_sum += a[i] - a[i - k];
		min_sum = min(min_sum, curr_sum);
	}
	return min_sum;
}

int main()
{
	int n, k, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	printf("%d", minSubarraySizeK(a, n, k));
 	return 0;
}
