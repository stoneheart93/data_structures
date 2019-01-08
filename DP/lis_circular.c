#include<stdio.h>
#include<limits.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int Lis(int a[], int start, int end)
{
	int lis[end - start];
    
    int i, j, max = 0;
    for(i = start; i < end; i++)
        lis[i] = 1;
    
    for(i = start + 1; i < end; i++)
    {
    	for(j = start; j < i; j++)
        {
            if(a[i] > a[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    for(i = start; i < end; i++)
    {
    	if(lis[i] > max)
        	max = lis[i];
    }
    return max;
}

int lisCircular(int a[], int n)
{
	int circBuff[2 * n]; 
	int i, j;
	
	for(i = 0; i < n; i++) 
		circBuff[i] = a[i]; 
	for(i = n; i < 2*n; i++) 
		circBuff[i] = a[i-n]; 
		
	int res = INT_MIN;
	for(i = 0; i < n; i++) 
		res = max(res, Lis(circBuff, i, i+n));
	
	return res;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", lisCircular(a,n));
    return 0;
}

