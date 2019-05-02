#include<stdio.h>

int advertise(int n)
{
    int sum = 0, likes = 0, share = 5;
    while(n--)
    {
        likes = share/2;
        sum += likes; 
        share = likes * 3;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", advertise(n));
    return 0;
}
