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

int findPivot(int a[], int low, int high)
{
	while(low <= high)
	{
		int mid = low + (high - low)/2;
	    if(mid < high && a[mid] > a[mid + 1])
	        return mid;
	    else if(mid >  low && a[mid] < a[mid - 1])
	        return mid - 1;
	
	    if(a[low] <= a[mid])
	    	low = mid + 1;
	    else
	        high = mid - 1;
   }
   return -1;
}

int searchSortedRotated(int a[], int n, int key)
{
	int pivot = findPivot(a, 0, n - 1);
	if(pivot == -1)
	    return binary_search(a, 0, n - 1, key);
	
	if(a[pivot] == key)
	    return pivot;
	else if(key < a[0])
	    return binary_search(a, pivot + 1, n - 1, key);
	else
	    return binary_search(a, 0, pivot - 1, key);
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

