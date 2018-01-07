#include<stdio.h>
#define INIT_MAX 999999
#define INIT_MIN 0
 
int findMaxDiff(int a[], int n)
{
    if(n < 2)
        return 0;
    
	int min_val = INIT_MAX, max_val = INIT_MIN;
	int i;
	
    for(i = 0; i < n; i++)
    {
        if((a[i] - i) > max_val)
            max_val = a[i] - i;
        if((a[i] - i) < min_val)
        	min_val = a[i] - i;
    }
    return (max_val - min_val);
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Maximum difference: %d", findMaxDiff(a, n));
	return 0;
}

