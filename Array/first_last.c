#include<stdio.h>
int n;

int first(int a[], int low, int high, int key)
{
	if(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == a[mid])
		{
			if(mid > 0 && a[mid] == a[mid - 1])
				return first(a, low, mid - 1, key);
			else
				return mid;			
		}
        else if(key < a[mid])
			return first(a, low, mid - 1, key);
		else 
        	return first(a, mid + 1, high, key);
   }
   return -1;
}

int last(int a[], int low, int high, int key)
{
	if(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == a[mid])
		{
			if(mid < n - 1 && a[mid] == a[mid + 1])
				return last(a, mid + 1, high, key);
			else
				return mid;			
		}
        else if(key < a[mid])
			return last(a, low, mid - 1, key);
		else 
        	return last(a, mid + 1, high, key);
   }
   return -1;
}

int main() 
{
    int i, key;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("\nFirst occurence: %d", first(a, 0, n - 1, key));
	printf("\nLast occurence: %d", last(a, 0, n - 1, key));
	return 0;
}

