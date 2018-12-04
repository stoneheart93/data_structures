#include<stdio.h>


int first(int a[], int n, int key)
{
	int low = 0, high = n - 1;
	int first = -1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == a[mid])
		{
			first = mid;
			high = mid - 1;		
		}
        else if(key < a[mid])
			high = mid - 1;
		else 
        	low = mid + 1;
   }
   return first;
}

int last(int a[], int n, int key)
{
	int low = 0, high = n - 1;
	int last = -1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == a[mid])
		{
			last = mid;
			low = mid + 1;		
		}
        else if(key < a[mid])
			high = mid - 1;
		else 
        	low = mid + 1;
   }
   return last;
}

int main() 
{
    int i, key, n;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("\nFirst occurence: %d", first(a, n, key));
	printf("\nLast occurence: %d", last(a, n, key));
	return 0;
}

