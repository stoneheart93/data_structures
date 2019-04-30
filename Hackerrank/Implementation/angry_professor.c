#include<stdio.h>

int main()
{
	int tc, n, k, i;
	scanf("%d", &tc);
	while(tc--)
	{
    	scanf("%d%d", &n, &k);
    	int count = 0;
		int a[n];
    	for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
       		if(a[i] <= 0)
       			count++;
    	}
    	if(count < k)
    		printf("YES\n");
    	else
    		printf("NO\n");
    }
    return 0;
}
