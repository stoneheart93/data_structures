#include<iostream>
#include<list>
using namespace std;
int N, E;
int E1[10000], E2[10000], W[1000];
int adj[1000][1000];
int residual[1000][1000];
int visited[1000];
int parent[1000];
#define INF 9999999

int BFS(int s, int t)
{
	for(int i = 1; i <= N; i++)
		visited[i] = 0;
	list<int> queue;
	visited[s] = 1;
	queue.push_back(s);
	while(!queue.empty())
	{
		int u = queue.front();
		queue.pop_front();
		for(int v = 1; v <= N; v++)
		{
			if(residual[u][v] > 0)
			{
				if(!visited[v])
				{
					visited[v] = 1;
					parent[v] = u;
					queue.push_back(v);
					if(v == t)
						return 1;
				}
			}
		}
	}
	return 0;
}

int ford_fulkerson(int s,int t)
{
    int max_flow = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            residual[i][j] = adj[i][j];
        }
    }
    while(BFS(s,t))
    {
        int path_flow = INF;
        for(int v = t; v != s; v = parent[v])
        {
        	int u = parent[v];
            path_flow = (path_flow < residual[u][v])? path_flow : residual[u][v];
        }
        for(int v = t; v != s; v = parent[v])
        {
        	int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
	int s, t;
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
    scanf("%d%d", &s, &t);
        
	for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            adj[i][j] = 0;
        }
    }
    for(int i = 1; i <= E; i++)
    {
        adj[E1[i]][E2[i]] = W[i];
    }
    cout << "Max flow: " << ford_fulkerson(s, t);
    return 0;
}

/* 
ip 
6 10
1 2 16
1 3 13
2 3 10
3 2 4
2 4 12
4 3 9
3 5 14
5 4 7
5 6 4
4 6 20
1 6
op
23
*/
