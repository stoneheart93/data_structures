#include<stdio.h> 

int multiplyBySeven(int n)
{
    return ((n << 3) - n);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", multiplyBySeven(n));
    return 0;
}
