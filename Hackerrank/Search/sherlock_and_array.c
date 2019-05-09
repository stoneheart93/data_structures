#include<stdio.h>

int isBalanced(int a[], int n)
{
    int sum = 0, leftsum = 0;
    int i;
    for(i = 0; i < n; i++)
        sum += a[i];

    for(i = 0; i < n; i++)
    {
        sum -= a[i];
        if(leftsum == sum)
            return 1;
        leftsum += a[i];
    }
    return 0;
}

int main()
{
    int tc, n, i;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        int* a = (int*) malloc(n * sizeof(int));
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if(isBalanced(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

