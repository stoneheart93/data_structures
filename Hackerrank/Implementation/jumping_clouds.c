#include<stdio.h>

int main()
{
	int n, i, jump = 0;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	i = 0;
	while(i < n)
	{
		if(i == n-1)
			break;
		if(a[i + 1] == 0  && a[i + 2] == 1)
		{
			jump++;
			i++;
		}
		else
		{
			jump++;
			i = i+2;
		}
	}
	printf("%d", jump);
	return 0;
}
