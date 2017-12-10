#include<stdio.h>

int nextPowerOf2(int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}  
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", nextPowerOf2(n));
    return 0;
}
 
