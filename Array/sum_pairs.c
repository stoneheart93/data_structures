#include<stdio.h>

int sumPairs(int a[], int n)
{
	int i;
    int sum = 0;
    for(i = n - 1; i >= 0; i--)
        sum += i * a[i] - (n - 1 - i)*a[i];
    return sum;
}
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", sumPairs(a, n));
	return 0;
}   
