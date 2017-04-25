#include<iostream>
using namespace std;
int N, E;
int adj[1000][1000];
int E1[1000], E2[1000], W[1000];
int mstSet[1000], key[1000], parent[1000];
#define INF 9999999

int minKey(int key[], int mstSet[])
{
    int min_index, min = INF;
    for (int i = 1; i <= N; i++)
    {
        if (mstSet[i] == 0 && key[i] < min) // <
        {
            min_index = i;
            min = key[i];
        }
    }
    return min_index;
}

void prim()
{
    for (int i = 1; i <= N; i++)
    {
        mstSet[i] = 0;
        key[i] = INF;
        parent[i] = -1;
    }

    key[1] = 0;

    for (int e = 1; e <= N - 1; e++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 1; v <= N; v++)
        {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v])  
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    
	for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << " " << i << " " << adj[i][parent[i]] << endl;
    }
}

int main()
{
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
    prim();
    return 0;
}

/*
ip
4 5
1 2 10
1 3 6
1 4 5
2 4 15
3 4 4
op
3 4 4
1 4 5
1 2 10
*/
