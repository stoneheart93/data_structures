#include<stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
 
int absMinSum(int a[], int b[], int n)
{
	qsort(a, n, sizeof(int), compare);
    qsort(b, n, sizeof(int), compare);
    
	int i, sum= 0 ;
    for(i = 0; i < n; i++)
    	sum += abs(a[i] - b[i]);
    return sum;
}

int main() 
{
    int n, i;
	int a[20], b[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]);
	printf("%d ", absMinSum(a, b, n));
	return 0;
}
