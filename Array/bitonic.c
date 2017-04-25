#include<stdio.h>
 
int bitonic(int a[], int n)
{
	int i, max;
    int inc[n]; 
    int dec[n]; 
    
    inc[0] = 1;
 	dec[n-1] = 1;
 
    for(i = 1; i < n; i++)
    {
    	if(a[i] > a[i - 1])
    		inc[i] = inc[i - 1] + 1;
    	else
			inc[i] = 1;
	}
    
	for(i = n-2; i >= 0; i--)
	{
		if(a[i] > a[i + 1])
    		dec[i] = dec[i + 1] + 1;
    	else
			dec[i] = 1;
	}
   
    max = inc[0] + dec[0] - 1;
    for(i = 1; i < n; i++)
    {
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;
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
	printf("Maximum length bitonic subarray: %d", bitonic(a, n));
	return 0;
}

/*
ip
6
12 4 78 90 45 23
op
Maximum length bitonic subarray: 5
*/
