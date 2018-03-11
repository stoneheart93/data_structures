#include<iostream>
#include<unordered_set>
using namespace std;

int printDistinct(int a[], int n)
{
    unordered_set<int> hash;
 
    for(int i = 0; i < n; i++)
        hash.insert(a[i]);
 
    for(auto it = hash.begin(); it != hash.end(); it++)
    {
    	printf("%d ",*it);
	}
}
 
int main()
{
    int n;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printDistinct(a, n);
    return 0;    
}    
