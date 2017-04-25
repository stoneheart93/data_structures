#include<stdio.h>

int add(int x, int y)
{
    if(y == 0)
        return x;
    else
        return add(x ^ y, (x & y) << 1);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", add(a, b));
    return 0;
}

