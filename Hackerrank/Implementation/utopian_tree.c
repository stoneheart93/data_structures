#include<stdio.h>

int utopianTree(int n) 
{
    int growth = 0;
    int i;
    for(i = 0; i <= n; i++)
    {
        if(i % 2 == 0)
            growth++;
        else
            growth *= 2;
    }
    return growth;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", utopianTree(n));
    }
    return 0;
}
