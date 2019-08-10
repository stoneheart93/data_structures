#include<stdio.h>
#include<limits.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int minSubarray(int a[], int n, int k)
{
	int start = 0, end;
	int sum = 0;
	int min_length = INT_MAX;
	
	for(end = 0; end < n; end++)
	{
		sum += a[end];
		while(sum >= k && start <= end)
		{
			min_length = min(min_length, end - start + 1);
			sum -= a[start++];
		}
	}
	
	return min_length;
}

int main()
{
	int n, k, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	printf("%d", minSubarray(a, n, k));
 	return 0;
}
