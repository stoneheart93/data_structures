#include<stdio.h>
#include<unordered_set>
using namespace std;
 
void printPairs(int a[], int n, int k)
{
	unordered_set<int> hash;
	
	for(int i = 0; i < n; i++)
  	{
		if (hash.find(k - a[i]) != hash.end())
        	printf("Pair with given sum %d is (%d, %d) \n", k, a[i], k - a[i]);
      	hash.insert(a[i]);
  	}
}
 
int main()
{
	int n, sum, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &sum);
	printPairs(a, n, sum);
 	return 0;
}

/*
ip
6
1 4 45 6 10 8
16
op
Pair with given sum 16 is (10, 6)
*/
