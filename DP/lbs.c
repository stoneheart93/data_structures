#include<stdio.h>

int lbs(int a[], int n )
{
	int i, j, max = 0;
	int lis[n], lds[n];
   
	for(i = 0; i < n; i++)
    	lis[i] = 1;
 
	for(i = 1; i < n; i++)
	{
    	for(j = 0; j < i; j++)
        {
			if(a[i] > a[j] && lis[i] < lis[j] + 1)
            	lis[i] = lis[j] + 1;
		}
	}
   	
	for(i = 0; i < n; i++)
    	lds[i] = 1;
 
	for(i = n - 2; i >= 0; i--)
	{
		for(j = n - 1; j > i; j--)
        {
			if(a[i] > a[j] && lds[i] < lds[j] + 1)
            	lds[i] = lds[j] + 1;
		}
	}
 
	for(i = 1; i < n; i++)
    {
    	if(lis[i] + lds[i] - 1 > max)
        	max = lis[i] + lds[i] - 1;
	}
	return max;
}
 
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", lbs(a, n));
	return 0;
}

/*
ip
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
op
7
*/
