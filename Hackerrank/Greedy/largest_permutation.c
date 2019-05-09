#include<stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void largePermutation(int a[], int n, long int k) 
{
    int *pos = (int *)malloc(n * sizeof(pos));
    for(int i = 0; i < n; i++)
        pos[a[i]] = i;

    int swaps = k > n ? n : k;

    for(int i = 0, j = n; i < swaps && j >= 1; i++, j--)
    {
        if(a[i] == j)
        {
            swaps++;
            continue;
        }

        // swapping of indices
        int temp = pos[j];
        pos[j] = i;
        pos[a[i]] = temp;

        swap(&a[i], &a[temp]);
    }
    free(pos);
}

int main() 
{
    int n;
    long int k;
    scanf("%d%lld", &n, &k);
    int *a = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    largePermutation(a, n, k);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
