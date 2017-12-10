#include<stdio.h>

void bin(int n)
{
    if(n > 1)
		bin(n/2);
    printf("%d", n % 2);
}
int main()
{
    int num;
    scanf("%d", &num);
    bin(num);
    return 0;
}
