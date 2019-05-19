#include<stdio.h>

int handshake(int n)
{
    return n * (n - 1) / 2;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", handshake(n));
    }
    return 0;
}
