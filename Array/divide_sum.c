#include<stdio.h>

int divideAndSum(int a[], int n)
{
	int sum = 0, i;
    for(i = 0; i < n; i++) 
	{
         
    	if(a[i] == 0) 
        	return -1;
         
        if (i == 0)
            sum += a[i];
        else
			sum += a[i] / a[i - 1];
    }
    return sum;
}

int main()
{
	int n, sum, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", divideAndSum(a, n));
	return 0;
} 
 
