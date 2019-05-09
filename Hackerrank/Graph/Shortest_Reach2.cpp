#include<iostream>
using namespace std;
int N, E;
int adj[3005][3005];
int E1[5000000], E2[5000000], W[5000000];
int dist[3005], spSet[3005];
#define INF 9999999

int minDist(int spSet[], int dist[])
{
    int min_index = 0, min = INF;
    for (int i = 1; i <= N; i++)
    {
        if (spSet[i] == 0 && dist[i] <= min)
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

    for (int i = 0; i < N - 1; i++)
    {
        int u = minDist(spSet, dist);
        spSet[u] = 1;
        for (int v = 1; v <= N; v++)
        {
            if (adj[u][v]!= INF && !spSet[v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
            
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i == src)
            continue;
        else if (dist[i] == INF)
        {
            dist[i] = -1;
            cout << dist[i] << " ";
        }
        else
            cout << dist[i] << " ";
    }
    cout << endl;


}
int main()
{
    //freopen("input.txt", "r", stdin);
    int T, src;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d%d", &N, &E);

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                adj[i][j] = INF;
            }
        }

        for (int i = 1; i <= E; i++)
        {

            scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
            if (W[i] < adj[E1[i]][E2[i]])
            {
                adj[E1[i]][E2[i]] = W[i];
                adj[E2[i]][E1[i]] = W[i];
            }
        }

        scanf("%d", &src);
        dijkstra(src);
    }
    return 0;
}
