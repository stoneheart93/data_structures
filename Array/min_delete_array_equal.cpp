#include<iostream>
#include<unordered_map>
using namespace std;
 
int minDelete(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
    	hash[a[i]]++;
 
    int max_count = 0;
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
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", minDelete(a, n));
    return 0;    
}
