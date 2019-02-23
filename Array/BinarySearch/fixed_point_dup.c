#include<stdio.h>

int min(int a, int b)
{
	return (a < b)? a : b;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

int index(int a[], int low, int high)
{
	if(low > high)
		return -1;
		
	int mid = low + (high - low) / 2;
	
	if(mid == a[mid])
		return mid;
		
	int left = index(a, low, min(a[mid], mid - 1));
	
	if(left >= 0)
		return left;
		
	return index(a, max(a[mid], mid + 1), high);
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", index(a, 0, n - 1));
	return 0;
}

