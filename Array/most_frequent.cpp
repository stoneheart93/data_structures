#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;
 
int mostFrequent(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
    	hash[a[i]]++;
 
    int max_count = INT_MIN, res = -1;
    for(auto it = hash.begin(); it != hash.end(); it++)
	{
	    if(it->second > max_count) 
		{
            res = it->first;
            max_count = it->second;
        }
    }
 
    return res;
}
 
int main()
{
    int n;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", mostFrequent(a, n));
    return 0;    
}
