#include<iostream>
#include<unordered_Set>
using namespace std;

int playGame(int a[], int n)
{
    unordered_set<int> hash;
 
    for(int i = 0; i < n; i++)
        hash.insert(a[i]);
 
    return (hash.size() % 2 == 0 ? 1 : 2);
}
 
int main()
{
    int n;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Player %d wins", playGame(a, n));
    return 0;    
}    
