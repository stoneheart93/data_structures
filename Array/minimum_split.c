#include<stdio.h>
#include<limits.h> 
 
int min(int a, int b)
{
	return ((a < b)? a : b);
}
int findMinSplit(int a[], int n)
{
	int i, sum = 0, leftsum = 0; 
	int element, minelement = INT_MAX;
	
	for (i = 0; i < n; i++)
        sum += a[i];
 
    for( i = 0; i < n; ++i)
   	{
   		leftsum += a[i];
    	sum -= a[i]; 
		if(leftsum > sum)
			minelement = min(minelement, leftsum - sum);
		else
			minelement = min(minelement, sum - leftsum);

	}	
    return minelement;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int minelement = findMinSplit(a, n);
	if(minelement == 0)
		printf("No extra element");
	else
		printf("%d", minelement);
	return 0;
}

/*
ip
6
3 2 1 5 7 8
op
4
*/
