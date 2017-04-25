#include<stdio.h>
#include<stdlib.h>

int overflow(int* result, int a, int b)
{
    *result = a + b;
    if(a > 0 && b > 0 && *result < 0)
        return 1;
    if(a < 0 && b < 0 && *result > 0)
        return 1;
    return 0;
}
int main()
{
    int *res = (int *)malloc(sizeof(int));
    int x = 2147483640;
    int y = 10;
    printf("%d\n", overflow(res,x,y));
    printf("%d\n", *res);
    return 0;
}
