#include<stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}
int minpages(int n, int p)
{
    return min(p/2, n/2 - p/2);
}
int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    printf("%d", minpages(n, p));
    return 0;
}
