#include<iostream>
#include<unordered_map>
using namespace std;

int printKDistinct(int a[], int n, int k)
{
	unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
    	hash[a[i]]++;
 
    if(hash.size() < k)
    	return -1;
 
    int dist_count = 0;
    for(int i = 0; i < n; i++)
    {
        if(hash[a[i]] == 1)
        	dist_count++;
        if(dist_count == k)
        	return a[i];
    }
    return -1;
}

int main()
{
    int n, k;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	printf("%d", printKDistinct(a, n, k));
    return 0;    
}     

/*
ip 
6
1 2 1 3 4 2
2
op
4
*/

