#include<stdio.h>
 
int search_rotated(int a[], int low, int high, int key)
{
	if(high >= low)
	{
		int mid = low + (high - low)/2;
    	if(key == a[mid])
			return mid;
    	
		if(a[low] <= a[mid])
    	{
        	if(key >= a[low] && key < a[mid])
				return search_rotated(a, low, mid - 1, key);
			else
				return search_rotated(a, mid + 1, high, key);
    	}
 		else
 		{
			if (key > a[mid] && key <= a[high])
        		return search_rotated(a, mid + 1, high, key);
			else
    			return search_rotated(a, low, mid - 1, key);
		}
    }
    return -1;
}
 
int main()
{
	int n, i, key;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("%d", search_rotated(a, 0, n - 1, key));
	return 0;
}

