#include<stdio.h>

void record(int a[], int n)
{
    int best = 0, worst = 0;
    int max = a[0], min = a[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
            best++;
        }
        if(a[i] < min)
        {
            min = a[i];
            worst++;
        }
    }
    printf("%d %d", best, worst);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    record(a, n);
    return 0;
}
