#include<iostream>
using namespace std;
int N, E;
int adj[1000][1000];
int E1[1000], E2[1000], W[1000];
int spSet[1000], dist[1000];
#define INF 9999999

int minDist(int dist[], int spSet[])
{
    int min_index, min = INF;
    for (int i = 1; i <= N; i++)
    {
        if (spSet[i] == 0 && dist[i] <= min) // <=
        {
            min_index = i;
            min = dist[i];
        }
    }
    return min_index;
}

void dijkstra(int src)
{
    for (int i = 1; i <= N; i++)
    {
        spSet[i] = 0;
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int e = 1; e <= N - 1; e++)
    {
        int u = minDist(dist, spSet);
        spSet[u] = 1;
        for (int v = 1; v <= N; v++)
        {
            if (adj[u][v] && !spSet[v] && dist[u] + adj[u][v] < dist[v]) 
            	dist[v] = dist[u] + adj[u][v];
        }
    }
    
	for (int i = 1; i <= N; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

int main()
{
	int src;
    scanf("%d%d", &N, &E);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (int i = 1; i <= E; i++)
    {
        scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
        adj[E1[i]][E2[i]] = W[i];
        adj[E2[i]][E1[i]] = W[i];
    }
    scanf("%d", &src);
    dijkstra(src);
    return 0;
}

/*
ip
9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
4 6 14
3 6 4
9 8 7
3 9 2
9 7 6
1
op
1 0
2 4
3 12
4 19
5 21
6 11
7 9
8 8
9 14
*/
