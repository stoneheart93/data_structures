#include<stdio.h>

int binary_search(int a[], int low, int high, int key)
{
	if(high >= low)
	{
		int mid = low + (high - low)/2;
		if(a[mid] == key)
			return mid;

        if(key < a[mid])
			return binary_search(a, low, mid - 1, key);
		else 
        	return binary_search(a, mid + 1, high, key);
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
	printf("Position: %d", binary_search(a, 0, n - 1, key));
	return 0;
}

