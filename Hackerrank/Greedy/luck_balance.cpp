#include<algorithm>
using namespace std;
#include<stdio.h>

bool compare(int a, int b)
{
    return a > b;
}
int maxmizeLuck(int L[], int T[], int n, int k)
{
    int result = 0, index = 0;
    int new_L[10004];
    for(int i = 0; i < n; i++)
    {
        if(T[i] == 0)
            result += L[i];
        else
            new_L[index++] = L[i];
    }

    int new_n = index;
    sort(new_L, new_L + new_n, compare);

    for(int i = 0; i < k; i++) 
       result += new_L[i];

    for(int i = k; i < new_n; i++)
        result -= new_L[i];

    return result;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int* L = (int*)malloc(n * sizeof(int));
    int* T = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d%d", &L[i], &T[i]);
    printf("%d", maxmizeLuck(L, T, n, k));
    return 0;
}
