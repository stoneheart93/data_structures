#include<iostream>
#include<unordered_set>
using namespace std;

void uniqueElements(int M[10][10], int m, int n)
{
	unordered_set<int> hash;
	
	for(int i = 0; i < m; i ++)
	{
		for(int j = 0; j < n; j++)
		{
			if(hash.find(M[i][j]) == hash.end())
				hash.insert(M[i][j]);
			else
				hash.erase(M[i][j]);
		}
	}	

	for(auto it = hash.begin(); it != hash.end(); it++)
	{
		printf("%d ", *it);
	}
}

int main() 
{
	int i, j, m, n;
	int M[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	
	uniqueElements(M, m, n);	
	return 0;
}

