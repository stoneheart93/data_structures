#include<stdio.h>

int bin_search(int a[], int n, int key)
{
	int low = 0, high = n - 1;
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

int main() 
{
    int n, i, key;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("%d", bin_search(a, n, key));
	return 0;
}

