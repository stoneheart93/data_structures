#include<iostream>
using namespace std;
int N, E;
int adj[3005][3005];
int E1[5000000], E2[5000000], W[5000000];
int mstSet[3005], key[3005];
#define INF 9999999

int minDist(int key[], int mstSet[])
{
    int min_index = 0, min = INF;
    for (int i = 1; i <= N; i++)
    {
        if (mstSet[i] == 0 && key[i] < min)
        {
			min_index = i;
        	min = key[i];
        }
    }
    return min_index;
}

void MST(int src)
{
    for (int i = 1; i <= N; i++)
    {
        mstSet[i] = 0;
        key[i] = INF;
    }

    key[src] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int u = minDist(key, mstSet);
        mstSet[u] = 1;
        for (int v = 1; v <= N; v++)
        {
            if (adj[u][v] != INF && !mstSet[v] && adj[u][v] < key[v])
                key[v] = adj[u][v];

        }
       
    }
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += key[i];
    }
    cout << sum<<endl;


}
int main()
{
	int T, src;
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
    MST(1);
    return 0;
}
