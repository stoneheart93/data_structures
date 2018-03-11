#include<iostream>
#include<unordered_map>
using namespace std;
 
int leastFrequent(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
    	hash[a[i]]++;
 
    int min_count = 9999999, res = -1;
    for(auto it = hash.begin(); it != hash.end(); it++)
	{
	    if(it->second < min_count) 
		{
            res = it->first;
            min_count = it->second;
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
	printf("%d", leastFrequent(a, n));
    return 0;    
}
