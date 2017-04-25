#include<iostream>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int tc[1000][1000];

void transitiveClosureUtil(int s, int u)
{
	tc[s][u] = 1;
	for(int v = 1; v <= N; v++)
	{
		if(adj[u][v])
		{
			if(!tc[s][v])
				transitiveClosureUtil(s, v);
		}
	}
}

void transitiveClosure()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			tc[i][j] = 0;
		}
	}

	for(int i = 1; i <= N; i++)
		transitiveClosureUtil(i, i);

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << tc[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int src;
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
    transitiveClosure();
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
1 1 1 1
1 1 1 1
1 1 1 1
0 0 0 1
*/
