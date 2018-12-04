#include<stdio.h>

int findMin(int a[], int low, int high)
{
	while(low <= high)
	{
		int mid = low + (high - low)/2;
	    if(mid < high && a[mid] > a[mid + 1])
	        return a[mid + 1];
	    else if(mid >  low && a[mid] < a[mid - 1])
	        return a[mid];
	
	    if(a[low] <= a[mid])
	    	low = mid + 1;
	    else
	        high = mid - 1;
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

	int min = findMin(a, 0, n-1);
	if(min == -1)
		printf("%d", a[0]);
	else
		printf("%d", min);
	return 0;
}

