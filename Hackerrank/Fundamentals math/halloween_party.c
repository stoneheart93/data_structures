#include<stdio.h>
#include<limits.h>

long int halloween(int n)
{
    long int max = INT_MIN;
    int i;
    for(i = 1; i <= n/2; i++)
    {
        long int pieces = (long int)i * (long int)(n - i);
        if(pieces > max)
            max = pieces;
    }
    return max;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%ld\n", halloween(n));
    }
    return 0;
}
