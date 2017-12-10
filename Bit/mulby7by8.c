#include<stdio.h> 

int multiplyBySevenByEight(int n)
{
    return ( ((n << 3) - n) >> 3 );
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", multiplyBySevenByEight(n));
    return 0;
}
