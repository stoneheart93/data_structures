#include<stdio.h>

int missing_no_sorted(int a[], int n) // index is the thing to be returned 
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		if(a[low] != low)
			return low;
		int mid = low + (high - low)/2;
		if(a[mid] == mid)
			low = mid + 1;
		else
			high = mid;
   }
   return high + 1;
}

int main() 
{
    int i, n;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", missing_no_sorted(a, n));
	return 0;
}

