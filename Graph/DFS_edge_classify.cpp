#include<iostream>
#include<stack>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int color[1000], parent[1000];
int start[1000], end[1000];
int t;

void DFS(int u)
{
	color[u] = 1;
	t = t + 1;
	start[u] = t;
	cout << "DFS " << u << endl;
	for(int v = 1; v <= N; v++)
	{
		if(adj[u][v])
		{
			if(color[v] == 2)
			{
				if(start[u] < start[v])
					cout << u << " " << v << " forward edge" << endl;
				else
					cout << u << " " << v << " cross edge" << endl;
			}
			if(color[v] == 1)
				cout << u << " " << v << " back edge" << endl;
			if(color[v] == 0)
			{
				cout << u << " " << v << " tree edge" << endl;
				parent[v] = u;
				DFS(v);
			}
		}
	}
	color[u] = 2;
	t = t + 1;
	end[u] = t;
}

void traverse(int src)
{
	for(int i = 1; i <= N; i++)
	{
		color[i] = 0;
		parent[i] = -1;
	}
	DFS(src);
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
DFS 3
3 1 tree edge
DFS 1
1 2 tree edge
DFS 2
2 3 back edge
1 3 back edge
3 4 tree edge
DFS 4
4 4 back edge
*/
