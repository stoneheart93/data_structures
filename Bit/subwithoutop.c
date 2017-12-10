#include<stdio.h>

int sub(int x, int y)
{
    if(y == 0)
        return x;
    else
        return sub(x ^ y, (~x & y) << 1);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", sub(a, b));
    return 0;
}

