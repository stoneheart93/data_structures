#include<stdio.h>
#include<stdlib.h>

int array_sum(int a[], int n)
{
    int i, sum = 0;
    for(i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int main()
{
    int n, i; 
    scanf("%d", &n);
    int* a = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
       scanf("%d", &a[i]);
    }
    
    printf("%d", array_sum(a, n));
    return 0;
}
