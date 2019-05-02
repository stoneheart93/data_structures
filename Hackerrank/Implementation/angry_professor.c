#include<stdio.h>

int cancellation(int a[], int n, int k)
{
	int i, count = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i] <= 0)
			count++;
	}
	if(count < k)
		return 1;
	else
		return 0;
}

int main()
{
	int tc, n, k, i;
	scanf("%d", &tc);
	while(tc--)
	{
    	scanf("%d%d", &n, &k);
    	int* a = (int*)malloc(n * sizeof(int));
    	for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
			
    	if(cancellation(a, n, k))
			printf("YES\n");
		else
			printf("NO\n");   	
	}
	return 0;
}
