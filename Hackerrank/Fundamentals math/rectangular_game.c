#include<stdio.h>
#include<limits.h>

int min(int a[], int n)
{
    int min = INT_MAX, i;
    for(i = 0; i < n; i++)
    {
        if(a[i] < min)
            min = a[i];
    }
    return min;
}

long int rectangular_game(int row[], int col[], int n)
{
    int min_row = min(row, n);
    int min_col = min(col, n);
    return (long int)min_row * (long int)min_col;
}
int main()
{
    int i, n;
    scanf("%d", &n);
    int row[n];
    int col[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &row[i], &col[i]);
    }
    printf("%ld", rectangular_game(row, col, n));
    return 0;
}

