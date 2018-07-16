#include<iostream>
#include<unordered_map>
using namespace std;
 
int firstNonRepeating(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
    	hash[a[i]]++;
 
    for(int i = 0; i < n; i++)
	{
		if(hash[a[i]] == 1) 
			return a[i];
    }
    return -1;
}
 
int main()
{
    int n;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", firstNonRepeating(a, n));
    return 0;    
}
