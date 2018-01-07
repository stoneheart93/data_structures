#include<stdio.h>

int floor_search(int a[], int low, int high, int key)
{
	if(high >= low)
	{
		if(key >= a[high])
        	return high;
 
		int mid = low + (high - low)/2;
		
		if(a[mid] == key)
			return mid;
		
		if(mid > 0 && key >= a[mid - 1] && key < a[mid])
        	return mid - 1;
 
 		if(key < a[mid]) 
        	return floor_search(a, low, mid - 1, key);
        else
        	return floor_search(a, mid + 1, high, key); 
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
	printf("Floor: %d", a[floor_search(a, 0, n - 1, key)]);
	return 0;
}

