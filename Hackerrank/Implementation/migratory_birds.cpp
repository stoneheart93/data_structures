#include<iostream>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int birds(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
        hash[a[i]]++;
        
    int size = hash.size();
    
    int i = 0;
    pair<int, int> s[size];
    for(auto it = hash.begin(); it != hash.end(); it++)
        s[i++] = make_pair(it->first, it->second);
        
    sort(s, s + size, compare);
    
    return s[0].first;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", birds(a, n));
    return 0;
}
