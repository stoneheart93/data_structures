#include<stdio.h>
#include<stdlib.h>

int count_pairs(int a[], int n, int k)
{
	int count = 0;
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if((a[i] + a[j]) % k == 0) 
				count++;
		}
	}	
	return count;
}

int main()
{
	int n, i, k;
	scanf("%d%d", &n, &k);
	int* a = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("%d", count_pairs(a, n, k));
	return 0;
}

