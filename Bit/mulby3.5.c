#include<stdio.h>

int mul3point5(int n)
{
    return ( (n << 1) + n + (n >> 1) );
}    
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", mul3point5(n));
    return 0;
}
