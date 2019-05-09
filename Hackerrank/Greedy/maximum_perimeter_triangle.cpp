#include<algorithm>
using namespace std;
#include<limits.h>
#include<stdio.h>

void largePerimeter(int a[], int n)
{
    sort(a, a + n);

    for(int i = n - 1; i >= 2; i--)
    {
        if(a[i-2] + a[i-1] > a[i]) 
        {
            printf("%d %d %d", a[i-2], a[i-1], a[i]);
            return;
        }
    }
    printf("-1");
}

int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    largePerimeter(a, n);
    return 0;
}

