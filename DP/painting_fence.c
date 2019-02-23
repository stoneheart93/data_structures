#include<stdio.h>

int paintFence(int n, int k)
{
	if(n == 0)
		return 0;
	
	if(n == 1)
		return k;
		
	int same = k * 1;
	int diff = k * (k - 1);
	
	int i;
	int same_new, diff_new;
	for(i = 3; i <= n; i++)
	{
		same_new = diff;
		diff_new = (same + diff) * (k - 1);
	}
	
	return same_new + diff_new;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d", paintFence(n, k));
	return 0;
}
