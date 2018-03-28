#include<stdio.h>

int binary_search(int a[], int n, int key)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == a[mid])
			return mid;
		else if(mid > low && key == a[mid - 1])
			return mid - 1;
		else if(mid < high && key == a[mid + 1])
			return mid + 1;
        else if(key < a[mid])
			high = mid - 2;
		else 
        	low = mid + 2;
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
	printf("Position: %d", binary_search(a, n, key));
	return 0;
}

