#include<stdio.h>

int xorValue(int a[], int n)
{
	if(n % 2 == 0)
		return 0;
	else
	{
		int res = 0;
		int i;
		for(i = 0; i < n; i++)
		{
			if(i % 2 == 0)
				res ^= a[i];
		}
		return res;
	}
}

int main()
{
	int t, n, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int a[n];
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		printf("%d\n", xorValue(a, n));
	}
	return 0;
}
