#include<stdio.h>

int getMissingNo(int a[], int n)
{
    int i, total;
    total = ((n+1) * (n+2))/2;   
    for(i = 0; i < n; i++)
    	total -= a[i];
    return total;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", getMissingNo(a, n));
 	return 0;
}

/*
ip
6
1 2 4 5 6
op
3
*/
