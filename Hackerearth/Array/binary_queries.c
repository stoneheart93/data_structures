//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/range-query-2/

#include<stdio.h>

int main()
{
    int N, Q;
    scanf("%d%d", &N, &Q);
    int* a = (int*)malloc(sizeof(int) * (N + 1));
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    
    int operation, L, R, flip;
    for(int i = 0; i < Q; i++)
    {
        scanf("%d", &operation);
        if(operation == 0)
        {
            scanf("%d%d", &L, &R);
            if(a[R] == 1)
                printf("ODD\n");
            else
                printf("EVEN\n");
        }
        else
        {
            scanf("%d", &flip);
            a[flip] = !a[flip];
        }
    }
    
    free(a);
    
    return 0;
}
