#include<stdio.h>

int divisibleBy3(int a[], int n)
{
    int digit = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        int num = a[i];
        while(num > 0)
        {
            int rem = num % 10;
            digit += rem;
            num /= 10;
        }
    }
    return (digit % 3 == 0);
}

int main()
{
    int t, n, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[n];
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if(divisibleBy3(a, n))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
