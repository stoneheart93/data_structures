#include<iostream>
using namespace std;
int N, E;
int E1[10000], E2[10000], W[10000];
int adj[1000][1000];
int dist[1000][1000];
#define INF 9999999

void floyd_warshall()
{   
    for(int i = 1; i <= N; i++)
    {
    	for(int j = 1; j <= N; j++)
        {
            dist[i][j] = adj[i][j];
        }
    }
    for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
    	{
    		for(int j = 1; j <= N; j++)
        	{
            	if(dist[i][k] + dist[k][j] < dist[i][j])
                	dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
	int src;
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
        
	for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
        	if(i == j)
            	adj[i][j] = 0;
            else 
            	adj[i][j] = INF;
        }
    }
    for(int i = 1; i <= E; i++)
    {
        adj[E1[i]][E2[i]] = W[i];
    }
    
	floyd_warshall();
    
	for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
        	(dist[i][j] == INF) ? cout << "INF " : cout << dist[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}

/*
ip
4 4
1 2 5
2 3 3
3 4 1
1 4 10
op
0	5	8	9
INF 0 	3 	4
INF INF 0 	1
INF	INF INF 0
*/
