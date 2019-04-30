#include <limits.h>
#include <stdio.h>

void miniMaxSum(long long int a[], int n) 
{
    int i;
    long long int sum = 0, max = INT_MIN, min = INT_MAX;
    for(i = 0; i < n; i++)
    {
        sum += a[i];
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];    
    }
    printf("%lld %lld\n", sum - max, sum - min);
}

int main()
{
    int n = 5;
    long long int a[5];
    int i;
    for(i = 0; i < n; i ++)
        scanf("%lld", &a[i]);
    miniMaxSum(a, n);
    return 0;
}
