#include<stdio.h>
#include<algorithm>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_except_one(int a[], int n, int k)
{
	swap(&a[k], &a[n - 1]);
	sort(a, a + n - 1);
	int last = a[n-1];
    for(int i = n - 1; i > k; i--)
    	a[i] = a[i-1];
	a[k] = last;
}


int main()
{
	int n, i, k;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	sort_except_one(a, n, k);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
