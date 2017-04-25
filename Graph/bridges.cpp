#include<iostream>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int visited[1000], parent[1000];
int disc[1000], low[1000];

void bridgeUtil(int u)
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
            	bridgeUtil(v);
				low[u] = min(low[u], low[v]);
				
				if(low[v] > disc[u])
					cout << u << " " << v << endl;
        	}
       	   	else if (v != parent[u])
            	low[u] = min(low[u], disc[v]);
        }
	}
}

void bridge()
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
    	if(!visited[i])
    		bridgeUtil(i);
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
        adj[E2[i]][E1[i]] = 1;
    }
    bridge();
    return 0;
}

/*
ip
5 5
2 1
1 3
3 2
1 4
4 5
op
4 5
1 4
*/
