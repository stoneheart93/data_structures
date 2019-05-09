#include<stdio.h>

unsigned int flipBits(unsigned int n)
{
    return ~n;
}

int main()
{
    int t;
    unsigned int n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%u", &n);
        printf("%u\n", flipBits(n));
    }
    return 0;
}
