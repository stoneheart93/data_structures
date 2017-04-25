#include<iostream>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int color[1000], parent[1000];

int isCycleUtil(int u)
{	
	color[u] = 1;
	for(int v = 1; v <= N; v++)
	{
		if(adj[u][v])
		{
			if(color[v] == 1)
				return 1;
			if(color[v] == 0)
			{
				parent[v] = u;
				if(isCycleUtil(v))
					return 1;
			}
		}
	}
	color[u] = 2;
	return 0;
}

int isCycle()
{
	for(int i = 1; i <= N; i++)
	{
		color[i] = 0;
		parent[i] = -1;
	}
	for(int i = 1; i <= N; i++)
	{
		if(color[i] == 0)
		{
			if(isCycleUtil(i))
				return 1;
		}	
	}
}

int main()
{
	scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d", &E1[i], &E2[i]);
        
	for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            adj[i][j] = 0;
        }
    }
    for(int i = 1; i <= E; i++)
    {
        adj[E1[i]][E2[i]] = 1;
    }
    if(isCycle())
    	cout << "There is a cycle";
    else
    	cout << "No cycle";
    return 0;
}

/* 
ip 
4 5
1 2 
1 3
2 3
3 4
3 1
op
There is a cycle
*/
