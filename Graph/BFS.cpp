#include<iostream>
#include<queue>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int visited[1000];

void BFS(int src)
{
	queue<int> q;
	visited[src] = 1;
	q.push(src);
	while(!q.empty())
	{
		int u = q.front();
		cout << u << " ";
		q.pop();
		for(int v = 1; v <= N; v++)
		{
			if(adj[u][v])
			{
				if(!visited[v])
				{
					visited[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

void traverse(int src)
{
	for(int i = 1; i <= N; i++)
		visited[i] = 0;
	BFS(src);
}

int main()
{
	int src;
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d", &E1[i], &E2[i]);
    scanf("%d", &src);
        
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
    traverse(src);
    return 0;
}

/* 
ip 
4 6
1 2 
1 3
2 3
3 4
4 4
3 1
3
op
3 1 4 2
*/
