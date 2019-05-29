#include<stdio.h>

int binary_search(int a[], int low, int high, int key)
{
	while(low <= high)
	{
		int mid = low + (high - low)/2;
	    if(key == a[mid])
	        return mid;
	    else if(key < a[mid])
	        high = mid - 1;
	    else
	        low = mid + 1;
   }
   return -1;
}

int findPivot(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
	    if(mid < high && a[mid] > a[mid + 1])
	        return mid + 1;
	    
	    if(a[low] <= a[mid])
	    	low = mid + 1;
	    else
	        high = mid - 1;
   }
   return 0;
}

int searchSortedRotated(int a[], int n, int key)
{
	int pivot = findPivot(a, n);
	
	if(pivot > 0 && key >= a[0] && key <= a[pivot - 1]) //left 
	    return binary_search(a, 0, pivot - 1, key);
	else // right/non rotated
	    return binary_search(a, pivot, n - 1, key);
}

int main()
{
	int n, i, key;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("%d", searchSortedRotated(a, n, key));
	return 0;
}

