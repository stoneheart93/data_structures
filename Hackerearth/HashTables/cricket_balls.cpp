// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/cricket-balls/description/

#include<unordered_map>
#include<iostream>
using namespace std;

int countPairSum(int a[], int n, int k)
{
    unordered_map<int, int> hash;
    int equal_count = 0, unequal_count = 0;
        
    for(int i = 0; i < n; i++)
        hash[a[i]]++;
        
    for(auto it = hash.begin(); it != hash.end(); it++)
    {  
        if(hash.find(k - it->first) != hash.end())
        {
            if(it->first == k - it->first) //nc2
                equal_count += (it->second * (it->second - 1)) / 2;
            else //nc1 * nc1
                unequal_count += it->second * hash[k - it->first];
        }
    }
   
    return equal_count + unequal_count / 2;
}

int main()
{
    int n, k, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int* a = new int[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &k);
            
        printf("%d\n", countPairSum(a, n, k));
        
        free(a);
    }        
    return 0;
}
