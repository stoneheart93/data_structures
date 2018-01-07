#include <stdio.h>

void rotateBy1(int a[], int n)
{
	int x = a[n-1], i;
	for(i = n - 1; i > 0; i--)
    	a[i] = a[i-1];
	a[0] = x;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	rotateBy1(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

