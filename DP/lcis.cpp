#include<iostream>
#include<unordered_map>
using namespace std;

int lcis(int a[], int n)
{
	unordered_map<int, int> hash;
	
    hash[a[0]] = 1;
    
    int max = 0;
    
	for(int i = 1; i < n; i++)
    {
    	hash[a[i]] = hash[a[i] - 1] + 1;
    	if(hash[a[i]] > max)
    		max = hash[a[i]];
	}
	return max;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", lcis(a,n));
    return 0;
}

