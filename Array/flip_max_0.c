#include<stdio.h>

int max(int a, int b)
{
	return (a > b)? a : b;
}

int findMax0(int a[], int n)
{
	int zero = 0;
	int max_so_far = 0;
	int curr_max = 0;
	int i;
 
   	for(i = 0; i < n; i++)
	{
		if(a[i] == 0)
			zero++;
		int val = (a[i] == 1) ? 1: -1;
        curr_max = max(a[i], curr_max + val);
        max_so_far = max(max_so_far, curr_max);
	}
	
	max_so_far = max(max_so_far, 0);
	return zero + max_so_far;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", findMax0(a, n));
	return 0;
}
