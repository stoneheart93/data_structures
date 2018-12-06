#include<iostream>
#include<unordered_set>
using namespace std;

void commonElements(int M[10][10], int m, int n)
{
	unordered_set<int> hash;
	for(int j = 0; j < n; j++)
		hash.insert(M[0][j]);
		
	for(int i = 1; i < m; i++)
	{
		unordered_set<int> temp;
		for(int j = 0; j < n; j++)
			temp.insert(M[i][j]);
		
		for(auto it = hash.begin(); it != hash.end(); it++)
		{
			if(temp.find(*it) == temp.end())
				hash.erase(*it);
		}
		
		if(hash.size() == 0)
			break;
	}
	
   	for(auto it = hash.begin(); it != hash.end(); it++)
    {
    	printf("%d ",*it);
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
	
	commonElements(M, m, n);	
	return 0;
}

