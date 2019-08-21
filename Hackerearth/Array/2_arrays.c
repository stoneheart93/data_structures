// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/2-arrays-90c9019c/description/

#include<stdio.h>

void make_sum_equal(int a[], int b[], int N)
{
    int a_count = 0, b_count = 0, a_sum = 0, b_sum = 0;
    for(int i = 0; i < N; i++)
    {
        if(a[i] == -1)
            a_count++;
        if(b[i] == -1)
            b_count++;
        a_sum += a[i];
        b_sum += b[i];
    }
    if(a_count == 1 && b_count == 1)
        printf("Infinite");
    else if(a_count == 0)
    {
        if(b_sum > a_sum)
            printf("0\n");
        else
        {
            if(b_count == 1)
                printf("1\n");
            else
                printf("%d\n", (a_sum - b_sum - 2) + 1);
        }
    }
    else if(b_count == 0)
    {
        if(a_sum > b_sum)
            printf("0\n");
        else
        {
            if(a_count == 1)
                printf("1\n");
            else
                printf("%d\n", (b_sum - a_sum - 2) + 1);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int* a = (int*)malloc(sizeof(int) * N);
    int* b = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &b[i]);
    
    make_sum_equal(a, b, N);
    
    free(a);
    free(b);
    
    return 0;
}
