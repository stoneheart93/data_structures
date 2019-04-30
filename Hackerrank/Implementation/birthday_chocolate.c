#include<stdio.h>

int chocolate_bar(int a[], int n, int d, int m)
{
    int i, j;
    int count = 0;
    for(i = 0; i+m-1 < n; i++)
    {
        int sum = 0;
        for(j = 0; j < m; j++)
            sum += a[i+j];
        if(sum == d)
            count++;
    }
    return count;
}

int main()
{
    int n, i, d, m;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d%d", &d, &m);
    printf("%d", chocolate_bar(a, n, d, m));
    return 0;
}
