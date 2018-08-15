#include<stdio.h>

/* For an array of size n, we have 2^n sub-sequences (including empty) in total. In total 2^n sub-sequences, 
each elements occurs 2^(n-1) times.
*/

int allSubsequenceSum(int a[], int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += a[i]; 
	return sum * (1 << (n - 1));
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", allSubsequenceSum(a, n));
	return 0;
}
