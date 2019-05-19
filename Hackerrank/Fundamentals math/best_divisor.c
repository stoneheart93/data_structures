#include<stdio.h>
#include<math.h>

int sum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int min(int a, int b)
{
    return (a < b ? a : b);
}
int bestDivisor(int n)
{
    int result = sum(n);
    int best_divisor;
    
    int i;
    for(i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            if(sum(i) > result) 
            {
                result = sum(i);
                best_divisor = i;
            }
            else if(sum(i) == result)
                best_divisor = min(i, n);
    
            if(i == n/i)
                continue;

            if(sum(n/i) > result) 
            {
                result = sum(n/i);
                best_divisor = n/i;
            }
            else if(sum(n/i) == result) 
                best_divisor = min(n/i, n);
        }
    }
    return best_divisor;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", bestDivisor(n));
    return 0;
}
