#include<iostream>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int visited[1000];

void DFS(int u)
{
	visited[u] = 1;
	for(int v = 1; v <= N; v++)
	{
		if(adj[u][v])
		{
			if(!visited[v])
				DFS(v);
		}
	}
}

int countComponents()
{
	int count = 0;
	for(int i = 1; i <= N; i++)
		visited[i] = 0;
	for(int i = 1; i <= N; i++)
	{
		if(!visited[i])
		{
			DFS(i);
			count++;
		}
	}
	return count;
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
    cout << "No of components: " << countComponents();
    return 0;
}

/* 
ip 
6 4
1 2
2 3
3 4
4 6
op
No of components: 2
*/
