#include<stdio.h>
#include<limits.h>

int transaction(int a[], int n)
{
	int maxProfit = 0;
    int i;
	
	for(i = 1; i < n; i++) 
	{
        if(a[i] > a[i - 1])
            maxProfit += a[i] - a[i - 1];
    }
    return maxProfit;	
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", transaction(a, n));
	return 0;
}

