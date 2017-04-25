#include<stdio.h>

void findNumbers(int a[], int p_n, int n)
{
    int num[n];
    int i;
    int b_minus_a = a[n-1] - a[1];
 
    // b is calculated here
    num[1] = (a[0] + b_minus_a) / 2;
 
    // a is calculated here
    num[0] = a[0] - num[1];
 
    // to calculate all the other numbers
    for(i = 1; i <= (n - 2); i++)
        num[i + 1] = a[i] - num[0];
 
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
}

int main() 
{
    int n, p_n, i;
	int a[20];
	scanf("%d", &n);
	scanf("%d", &p_n);
	for(i = 0; i < p_n; i++)
		scanf("%d", &a[i]);
	findNumbers(a, p_n, n);
	return 0;
}

