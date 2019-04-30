#include<stdio.h>

int main()
{
	int n, k, charged, i;
	scanf("%d%d", &n, &k);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &charged);
	
	int sum = 0;
	for(i = 0; i < n; i++)
	{
		if(i != k)
			sum += a[i];	
	}	
	if(charged == sum/2)
		printf("Bon Appetit");
	else
		printf("%d", charged - sum / 2);
	return 0;
}

