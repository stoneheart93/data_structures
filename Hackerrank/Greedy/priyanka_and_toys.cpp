#include<algorithm>
using namespace std;
#include<stdio.h>


int toys(int a[], int n)
{
    int count = 0;
    sort(a, a + n);
    
    int i = 0;
    while(i < n)
    {
        int y = a[i] + 4;
        while(a[i] <= y)
            i++;
        count++;
    }
    return count;
}



int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", toys(a, n));
    return 0;
}

