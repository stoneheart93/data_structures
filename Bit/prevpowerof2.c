#include<stdio.h>

int isPowerOfTwo(int n)
{
    return (n && (! (n & (n - 1))) );
}

int prevPowerOf2(int n)
{
    int res = 0;
    int i;
    for(i = n; i >= 1; i--) 
    { 
        if(isPowerOfTwo(i)) 
        { 
            res = i; 
            break; 
        } 
    } 
    return res; 
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", prevPowerOf2(n));
    return 0;
}

// Note: Please see https://www.geeksforgeeks.org/highest-power-2-less-equal-given-number/ application problem
