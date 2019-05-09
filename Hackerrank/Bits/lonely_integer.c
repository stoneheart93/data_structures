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
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", lonely_integer(a, n));
	return 0;
}
