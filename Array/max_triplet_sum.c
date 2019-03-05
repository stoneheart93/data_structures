#include<stdio.h>
#include<limits.h>

int maxTripletSum(int a[], int n)
{
	int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
	int i;
 
    for(i = 0; i < n; i++) 
	{
		if(a[i] > maxA) 
		{
        	maxC = maxB;
        	maxB = maxA;
        	maxA = a[i];
        }
		else if(a[i] > maxB) 
		{
            maxC = maxB;
            maxB = a[i];
        }
        else if(a[i] > maxC)
			maxC = a[i];
    }
	return (maxA + maxB + maxC);
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", maxTripletSum(a, n));
	return 0;
}

/*
ip
6
1 0 8 6 4 2
op
18
*/
