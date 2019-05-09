#include<iostream>
using namespace std;
int N, E;
int adj[1005][1005];
int dist[1005][1005];
int E1[10000], E2[10000], W[10000];
#define INF 99999999

void floydwarshell()
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
	int Q, from, to;
    scanf("%d%d", &N, &E);
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
        scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
        adj[E1[i]][E2[i]] = W[i];
    }        
    
    floydwarshell();
    
    scanf("%d", &Q);
    for(int i = 1; i <= Q; i++)
    {
        scanf("%d%d", &from, &to);
        if(dist[from][to] == INF)
            dist[from][to] = -1;
        printf("%d\n", dist[from][to]);
    }
    
    return 0;
}
