#include<stdio.h>
#include<math.h>
#define EPS 1e-9

void productArray(int a[], int n)
{
	int i;
	long double sum = 0; 
	for(i = 0; i < n; i++)
		sum += (long double)log10(a[i]);

	for(i = 0; i < n; i++)
		printf("%d ", (int)(EPS + pow((long double)10.00, sum - log10(a[i])) )); 
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	productArray(a, n);
	return 0;
}

/*
ip
5
10 3 5 6 2
op
180 600 360 300 900
*/
