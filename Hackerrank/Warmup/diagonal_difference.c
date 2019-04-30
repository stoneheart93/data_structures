#include<stdio.h>
#include<stdlib.h>

int diffDiagonals(int** a, int n)
{
    int p_sum = 0, s_sum = 0;
    int i;

    for(i = 0; i < n; i++)
        p_sum += a[i][i];
        
    for(i = 0; i < n; i++)
        s_sum += a[i][n-1-i];
        
    return (p_sum > s_sum ? p_sum - s_sum : s_sum - p_sum);
}

int main()
{    
    int n, i, j; 
    scanf("%d", &n);
    
    int** a = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
        a[i] = (int*)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
           {
            scanf("%d", &a[i][j]);
           }
    }
    
    printf("%d", diffDiagonals(a, n));
    return 0;
}

