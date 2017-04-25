#include<stdio.h>

int isPowerOfTwo(int n)
{
    return (n && (! (n & (n - 1))) );
}
int main()
{
    int n;
    scanf("%d", &n);
    if(isPowerOfTwo(n))
       printf("%d is a power of 2", n);
    else
       printf("%d is not a power of 2", n);
    getch();
    return 0;
}
