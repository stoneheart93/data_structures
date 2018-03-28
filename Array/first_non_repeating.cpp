#include<iostream>
#include<unordered_map>
using namespace std;
 
void firstNonRepeating(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
    	hash[a[i]]++;
 
    for(auto it = hash.begin(); it != hash.end(); it++)
	{
	    if(it->second == 1) 
			printf("%d ", it->first);
    }
}
 
int main()
{
    int n;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	firstNonRepeating(a, n);
    return 0;    
}
