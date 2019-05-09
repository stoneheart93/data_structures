#include<unordered_map>
#include<iostream>
using namespace std;
#include<limits.h>

int minDeletions(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
        hash[a[i]]++;

    int max_count = INT_MIN;
    for(auto it = hash.begin(); it != hash.end(); it++)
    {
        if(it->second > max_count)
            max_count = it->second;
    }
    return n - max_count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", minDeletions(a, n));
    return 0;
}
