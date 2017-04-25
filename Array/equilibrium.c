#include<stdio.h>
 
int equilibrium(int a[], int n)
{
	int i, sum = 0, leftsum = 0; 
	
	for (i = 0; i < n; i++)
        sum += a[i];
 
    for( i = 0; i < n; ++i)
   	{
    	sum -= a[i]; 
		if(leftsum == sum)
        	return i;
		leftsum += a[i];
   	}	
 
    return -1;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Equilibrium: %d", equilibrium(a, n));
	return 0;
}

/*
ip
7
-7 1 5 2 -4 3 0
op
Equilibrium: 3
*/
