#include<stdio.h>

int floor_search(int a[], int n, int key)
{
	int low = 0, high = n - 1;
	int floor = -1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == a[mid])
			return a[mid];
		else if(key < a[mid])
			high = mid - 1;
		else
		{ 
			floor = a[mid];
        	low = mid + 1;
        }
   }
   return floor;
}

int ceil_search(int a[], int n, int key)
{
	int low = 0, high = n - 1;
	int ceil = -1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == a[mid])
			return a[mid];
        else if(key < a[mid])
        {
			ceil = a[mid];
			high = mid - 1;
		}
		else 
        	low = mid + 1;
   }
   return ceil;
}

int main() 
{
    int i, key, n;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("\nFloor: %d", floor_search(a, n, key));
	printf("\nCeil: %d", ceil_search(a, n, key));
	return 0;
}

