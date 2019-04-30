#include<stdio.h>

int lonely_integer(int a[], int n)
{
	int i, res = 0;
	for(i = 0; i < n; i++)
	{
		res = res ^ a[i];
	}
	return res;
}

int main()
{
	int n, i, res;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		printf("%d\n", a[i]);
	
	}
	for(i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	res = lonely_integer(a, n);
	printf("%d", res);
	return 0;
}
