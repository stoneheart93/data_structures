#include<algorithm>
using namespace std;
#include<stdio.h>

int toys(int a[], int n, long int amount)
{
    sort(a, a + n);
    int count = 0;
    long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += (long)a[i];
        if(sum < amount)
            count++;
        else
            break;
    }
    return count;
}

int main()
{
    int n;
    long int amount;
    scanf("%d%lld", &n, &amount);
    int* a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", toys(a, n, amount));
    return 0;
}
