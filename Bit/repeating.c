#include<stdio.h>

int repeating(int a[], int n)
{
	int res = 0, i;
	for(i = 0; i < n - 1; i++)
       res = res ^ (i + 1) ^ a[i];
	res = res ^ a[n-1];
    return res;
}

int main()
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", repeating(a, n));
    return 0;    
}
