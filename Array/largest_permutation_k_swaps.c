#include<stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void largePermutation(int a[], int n, int k) 
{
    int pos[n + 1];
    int i, j;
    
    for(i = 0; i < n; i++)
        pos[a[i]] = i;

    int swaps = k > n ? n : k;

    for(i = 0, j = n; i < swaps && j >= 1; i++, j--)
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
}

int main() 
{
    int n, k, i;
    int a[20];
	scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    largePermutation(a, n, k);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
