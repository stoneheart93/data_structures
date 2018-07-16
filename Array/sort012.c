#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort012(int a[], int n)
{
	int low = 0, mid = 0, high = n - 1;
	while(mid <= high)
	{
		switch(a[mid])
		{
			case 0: swap(&a[low++], &a[mid++]);
					break;
			case 1: mid++;
					break;
			case 2: swap(&a[mid], &a[high--]);
					break;
		}
	}
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort012(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
