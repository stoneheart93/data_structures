#include<unordered_map>
#include<iostream>
using namespace std;

void sumUp(int a[], int n, int k)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
        hash[a[i]] = i;

    for(int i = 0; i < n; i++)
    {
        if(hash.find(k - a[i]) != hash.end())
        {
            int j = hash.find(k - a[i])->second;
            if(i != j)
            {
                printf("%d %d\n", i + 1, j + 1);
                hash.erase(a[i]);
            }
        }
    }
}

int main()
{
    int tc, n, i, k;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &k);
        scanf("%d", &n);
        int* a = (int*) malloc(n * sizeof(int));
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sumUp(a, n, k);
    }
    return 0;
}

