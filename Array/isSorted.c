#include<stdio.h>

int isSorted(int a[], int n)
{
	if(n == 0 || n == 1)
    	return 1;
 
 	int i;
    for(i = 1; i < n; i++)
	{
        if(a[i-1] > a[i])
            return 0;
    }
    return 1;
}


int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if(isSorted(a, n))
		printf("Sorted");
	else
		printf("Not sorted");
	return 0;
}

