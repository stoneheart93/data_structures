#include<stdio.h>
#include<limits.h>

int large(int a[], int n, int k)
{
    int max = INT_MIN;
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return (max > k ? max - k : 0);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", large(a, n, k));
    return 0;
}
