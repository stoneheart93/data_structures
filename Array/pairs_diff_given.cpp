#include<stdio.h>
#include<unordered_set>
using namespace std;
 
void printPairs(int a[], int n, int k)
{
	unordered_set<int> hash;
	
	for(int i = 0; i < n; i++)
      	hash.insert(a[i]);

	for(int i = 0; i < n; i++)
  	{
		if (hash.find(a[i] + k) != hash.end())
        	printf("Pair with given difference %d is (%d, %d) \n", k, a[i], a[i] + k);
        	
        if (hash.find(a[i] - k) != hash.end())
        	printf("Pair with given difference %d is (%d, %d) \n", k, a[i], a[i] - k);
        	
        hash.erase(a[i]);
  	}
}
 
int main()
{
	int n, diff, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &diff);
	printPairs(a, n, diff);
 	return 0;
}

