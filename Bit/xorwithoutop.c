#include<stdio.h>

int Xor(int x, int y)
{
    return (x | y) & (~x | ~y);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", Xor(a, b));
    return 0;
}

