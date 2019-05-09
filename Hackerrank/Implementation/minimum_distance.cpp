#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;
#include<limits.h>

int min(int a, int b)
{
    return a < b ? a : b;
}
int minDistance(int a[], int n)
{
    unordered_map<int, vector<int>> hash;
    for(int i = 0; i < n; i++)
    {
        if(hash.find(a[i]) != hash.end())
            hash[a[i]].push_back(i); 
        else
        {
            vector<int> temp;
            temp.push_back(i);
            hash[a[i]] = temp;
        }
    }

    int min_count = INT_MAX;
    for(auto it = hash.begin(); it != hash.end(); it++)
    {
        vector<int> temp = it->second;
        int s = temp.size();
        if(s > 1)
            min_count = min(min_count, abs(temp[s-1] - temp[s-2]));
    }
    return min_count != INT_MAX ? min_count : -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", minDistance(a, n));
    return 0;
}

