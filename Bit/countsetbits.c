#include<stdio.h>

int countSetBits(int n)
{
    int count = 0;
    while(n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", countSetBits(a));
    return 0;
}
