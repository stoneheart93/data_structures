#include <stdio.h>
 
int maxitimesAi(int a[], int n)
{
	int i, j;
	int array_sum = 0, cur_val = 0;
	for(i = 0; i < n; i++)
	{
		array_sum += a[i];
		cur_val += i * a[i];
	}
	
	int max_val = cur_val;
	
	for(j = 1; j < n; j++)
	{
		cur_val += array_sum - n * a[n - j];
		if(cur_val > max_val)
			max_val = cur_val;
	}
	
	return max_val;
}    
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", maxitimesAi(a, n));
	return 0;
}

