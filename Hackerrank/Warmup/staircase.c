#include<stdio.h>

void staircase_pattern(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-1-i; j++)
            printf(" ");
        for(j = 0; j < i+1; j++)
            printf("#");
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    staircase_pattern(n);
    return 0;
}
