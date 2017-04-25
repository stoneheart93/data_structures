#include<iostream>
#include<list>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int colorArr[1000];

int isBipartite()
{
	for(int i = 1; i <= N; i++)
		colorArr[i] = -1;
	
	list<int> queue;
	colorArr[1] = 1;
	queue.push_back(1);
	while(!queue.empty())
	{
		int u = queue.front();
		queue.pop_front();
		for(int v = 1; v <= N; v++)
		{
			if(adj[u][v])
			{
				if(colorArr[v] == -1)
				{
					colorArr[v] = 1 - colorArr[u];
					queue.push_back(v);
				}
				else if(colorArr[v] == colorArr[u])
					return 0;
			}
		}
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
    if(isBipartite())
		cout << "Bipartite";
	else
		cout << "Not Bipartite";
	return 0;
}

/* 
ip 
4 4
1 2 
1 4
3 2
3 4
op
Bipartite
*/
