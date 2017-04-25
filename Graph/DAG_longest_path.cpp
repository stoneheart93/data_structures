#include<iostream>
#include<stack>
using namespace std;
int N, E;
int E1[1000], E2[1000], W[1000];
int visited[1000];
int adj[1000][1000];
int dist[1000];
stack<int>Stack;
#define INF 9999999

void topologicalSortUtil(int u)
{
    visited[u] = 1;
    for(int v = 1; v <= N; v++)
    {
        if(adj[u][v])
        {
            if(!visited[v])
    	        topologicalSortUtil(v);
        }
	}
    Stack.push(u);
}
void topologicalSort()
{
    for(int i = 1; i <= N; i++)
        visited[i] = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
            topologicalSortUtil(i);
    }
}
void longestPath(int src)
{
    for(int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[src] = 0;
    topologicalSort();
     
    while(!Stack.empty())
    {
        int u = Stack.top();
        Stack.pop();
        for(int v = 1; v <= N; v++)
        {
            if(adj[u][v])
            {
                if(dist[u] + adj[u][v] * -1 < dist[v])
        			dist[v] = dist[u] + adj[u][v] * -1;
        	}
    	}
    }
    for(int i = 1; i <= N; i++)
    	cout << i << " " << dist[i] * -1 << endl;
}
int main()
{
	int src;
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            adj[i][j] = 0;
        }
    }
	for(int i = 1; i <= E; i++)
    {
		scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
		adj[E1[i]][E2[i]] = W[i];
	}
    scanf("%d", &src);
    longestPath(src);
    return 0;
}

/*
ip
6 10
1 2 5
1 3 3
2 4 6
2 3 2
3 5 4
3 6 2
3 4 7
4 6 1
4 5 -1
5 6 -2
2
op
1 INF
2 0
3 2
4 9
5 8
6 10
*/
