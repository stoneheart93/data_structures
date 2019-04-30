#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int findFloor(int a[], int n, int key)
{
    int floor = -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(key == a[mid])
            return key;
        else if(key < a[mid])
            high = mid - 1;
        else
        {
            floor = a[mid];
            low = mid + 1;
        }
    }
    return floor;
}

int max_sum(int a[], int m, int b[], int n, int amount)
{
    int max = -1;
    sort(a, a + m);
    sort(b, b + n);
    for(int i = 0; i < m; i++)
    {
        int element = amount - a[i];
        int fl = findFloor(b, n, element);
        if(fl == -1)
            break;
        if(a[i] + fl > max)
            max = a[i] + fl;
    }
    return max;
}

int main()
{
    int m, n, amount, i;
    scanf("%d%d%d", &amount, &m, &n);
    int* a = (int*)malloc(m * sizeof(int));
    int* b = (int*)malloc(n * sizeof(int));
    for(i = 0; i < m; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);
    printf("%d", max_sum(a, m, b, n, amount));
    return 0;
}

