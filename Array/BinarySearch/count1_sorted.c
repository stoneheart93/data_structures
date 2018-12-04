#include<stdio.h>

int last_1(int a[], int n)
{
	int low = 0, high = n - 1;
	int last = -1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(a[mid] == 1)
		{
			last = mid;
			low = mid + 1;		
		}
        else
			high = mid - 1;
   }
   return last;
}

int main() 
{
    int i, n;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	printf("%d", last_1(a, n) + 1);
	return 0;
}

