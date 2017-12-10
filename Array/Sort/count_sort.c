#include<stdio.h>

void count_sort(int a[], int b[], int k, int n)
{
	int c[k + 1];
    int i, j;
    
    for(i = 0; i <= k; i++)
    	c[i] = 0;
	
	for(i = 0; i < n; i++)
    	c[a[i]] = c[a[i]] + 1;
    
	for(i = 1; i <= k; i++)
    	c[i] += c[i - 1];
    	
    for(i = n - 1; i >= 0; i--)
    {
        b[c[a[i]]] = a[i];
		c[a[i]] = c[a[i]] - 1;
    }
 
    for(i = 0, j = 1; i < n; i++, j++)
		a[i] = b[j];
}

int getMax(int a[], int n)
{
	int i;
	int max = -1;
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

int main() 
{
    int n, i;
	int a[20], b[20];
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	 
	int range = getMax(a, n);
	
	count_sort(a, b, range, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
