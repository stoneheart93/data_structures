#include<stdio.h>

int sock_pairs(int a[], int n)
{
	int count = 0;
	static int c[105];
	int i;
	for(i = 0; i < n; i++)
	{
		if(c[a[i]])
		{
			c[a[i]] = 0;
			count++;
		}
		else
			c[a[i]] = 1;
	}
	return count;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", sock_pairs(a, n));
	return 0;
}
