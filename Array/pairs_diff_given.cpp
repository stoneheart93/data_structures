#include<stdio.h>
#include<unordered_set>
using namespace std;
 
void printPairs(int a[], int n, int diff)
{
	int i, temp;
	unordered_set<int> hash;
	
	for(i = 0; i < n; i++)
      	hash.insert(a[i]);

	for(i = 0; i < n; i++)
  	{
		temp = diff + a[i];
		if (hash.find(temp) != hash.end())
        	printf("Pair with given difference %d is (%d, %d) \n", diff, a[i], temp);
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

