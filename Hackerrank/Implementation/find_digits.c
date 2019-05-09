#include<stdio.h>

int findDigits(int n)
{
    int count = 0;
    int number = n;
    while(n)
    {
        int rem = n % 10;
        if(rem != 0 && number % rem == 0)
            count++;
        n /= 10;
    }
    return count;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", findDigits(n));
    }
    return 0;
}
