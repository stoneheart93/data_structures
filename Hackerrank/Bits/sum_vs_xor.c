#include<stdio.h>
#include<math.h>

long int sumXor(long int n)
{
    int count = 0;
    
    while(n)
    {
        if(!(n & 1))
            count++;
        n >>= 1;
    }

    return 1L << count;
}

int main()
{
    long int n;
    scanf("%lld", &n);
    printf("%lld", sumXor(n));
    return 0;
}

