#include<stdio.h>

void rev(int a[], int start, int end)
{
    if(start >= end)
        return;
    int temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    rev(a, start + 1, end - 1);
}

void left_rotate(int a[], int n, int d)
{
    rev(a, 0, d - 1);
    rev(a, d, n - 1);
    rev(a, 0, n - 1);
}

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int a[n];
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    left_rotate(a, n, d);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
