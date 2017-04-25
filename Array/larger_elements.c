#include<stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
 
void findLarger(int a[], int n)
{
	int i;
	qsort(a, n, sizeof(int), compare);
    for(i = n-1; i >= n/2; i--)
		printf("%d ", a[i]);
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	findLarger(a, n);
	return 0;
}

/*
ip
6
1 3 6 1 0 9
op
9 6 3
*/
