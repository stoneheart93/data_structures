//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/monk-and-welcome-problem/

#include<stdio.h>

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
    
    for(int i = 0; i < N; i++)
        printf("%d ", a[i] + b[i]);
    
    free(a);
    free(b);
    
    return 0;
}
