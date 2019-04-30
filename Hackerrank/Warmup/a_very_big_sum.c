#include<stdio.h>
#include<stdlib.h>

int array_sum(long int a[], int n)
{
    int i;
	long int sum = 0;
    for(i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int main()
{
    int n, i; 
    scanf("%d", &n);
    long int* a = (long int*) malloc(n * sizeof(long int));
    for(i = 0; i < n; i++)
    {
       scanf("%ld", &a[i]);
    }
    
    printf("%ld", array_sum(a, n));
    return 0;
}
