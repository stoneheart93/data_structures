#include<stdio.h>

void count_sort(int a[], int n, int exp)
{
    int b[n+1], c[10];
    int i, j;
 
	for(i = 0; i < 10; i++)
		c[i] = 0;
    
	for(i = 0; i < n; i++)
        c[(a[i]/exp)%10]++;
 
    for(i = 1; i < 10; i++)
        c[i] += c[i - 1];
 
    for(i = n - 1; i >= 0; i--)
    {
        b[c[(a[i]/exp)%10]] = a[i];
        c[(a[i]/exp)%10]--;
    }
 
    for(i = 0, j = 1; i < n; i++, j++)
        a[i] = b[j];
}

int getMax(int a[], int n)
{
	int i;
	int max = -1;
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}
 
void radix_sort(int a[], int n)
{
	int m = getMax(a, n);
 	int exp;
    for(exp = 1; m/exp > 0; exp *= 10)
        count_sort(a, n, exp);
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	radix_sort(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
