#include <limits.h>
#include <stdio.h>

int birthdayCandles(int a[], int n) 
{
    int i, count = 0;
    int max = INT_MIN;
    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    for(i = 0; i < n; i++)
    {
        if(a[i] == max)
        {    
            count++;
        }
    }
    return count;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    printf("%d", birthdayCandles(a, n));
    return 0;
}
