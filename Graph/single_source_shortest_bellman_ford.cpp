#include<iostream>
using namespace std;
int N, E;
int E1[1000], E2[1000], W[1000];
int dist[1000];
#define INF 9999999

void BellmanFord(int src)
{
	for(int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[1] = 0;
     
    for(int j = 1; j <= N-1; j++)
    {
        for(int i = 1; i <= E; i++)
        {
            int u = E1[i];
            int v = E2[i];
            if(dist[v] > dist[u] + W[i])
                dist[v] = dist[u] + W[i];
        }
    }
     
    for(int i = 1; i <= E; i++)
    {
        int u = E1[i];
        int v = E2[i];
        if(dist[v] > dist[u] + W[i])
            cout << "Graph contains negative cycles";
    }
     
    for(int i = 1; i <= N; i++)
    	cout << i << " " << dist[i] << endl;
}
     
int main()
{
	int src;
    scanf("%d%d", &N, &E);
    for (int i = 1; i <= E; i++)
        scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
    scanf("%d", &src);
	BellmanFord(src);
    return 0;
}

/*
ip
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 3 5
4 2 1
5 4 -3
1
op
1 0 
2 -1
3 2 
4 -2 
5 1
*/
