#include<stdio.h>

int max(int a, int b)
{
	return (a > b)? a : b;
}

int kadane(int a[], int n)
{
	int max_so_far = a[0];
	int curr_max = a[0];
	int i;
 
	for(i = 1; i < n; i++)
	{
	    curr_max = max(a[i], //the subarray could start from the element
					curr_max + a[i]); //the subarray could contain the previous sum + this element
        max_so_far = max(max_so_far, curr_max);
	}
   	return max_so_far;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", kadane(a, n));
	return 0;
}
