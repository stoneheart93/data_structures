#include<stdio.h>

int index(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(mid == a[mid])
			return mid;
		else if(mid < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
   }
   return -1;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", index(a, n));
	return 0;
}

