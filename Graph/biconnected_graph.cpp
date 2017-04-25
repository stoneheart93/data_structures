#include<iostream>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int visited[1000], parent[1000];
int disc[1000], low[1000];

int isBCUtil(int u)
{
	static int time = 0;
	int children = 0;
	visited[u] = 1;
	disc[u] = low[u] = ++time;
	
	for(int v = 1; v <= N; v++)
  	{
        if(adj[u][v])
        {
        	if (!visited[v])
        	{
            	children++;
            	parent[v] = u;
            	if(isBCUtil(v))
            		return 1;
				low[u] = min(low[u], low[v]);
				
				if (parent[u] == -1 && children > 1)
               		return 1;
				if (parent[u] != -1 && low[v] >= disc[u])
               		return 1;
        	}
       	   	else if (v != parent[u])
            	low[u] = min(low[u], disc[v]);
        }
	}
	return 0;
}

int isBC()
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
    }

	if(isBCUtil(1))
    	return 0;
    	
	for (int i = 1; i <= N; i++)
	{
        if(!visited[i])
            return 0;
    }
    return 1;
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
        adj[E2[i]][E1[i]] = 1;
    }
    if(isBC())
    	cout << "Biconnected graph";
    else
    	cout << "Not biconnected graph";
    return 0;
}

/*
ip
3 2
1 2 
2 3
op
Not biconnected graph
*/
