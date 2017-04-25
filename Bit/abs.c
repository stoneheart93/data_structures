#include <stdio.h>

int getAbs(int n)
{
    int mask = n >> (sizeof(int) * 8 - 1);
    return ((n + mask) ^ mask);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("Absoute value of %d is %d", n, getAbs(n));
    return 0;
}
