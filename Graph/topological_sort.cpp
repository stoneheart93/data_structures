#include<iostream>
#include<stack>
using namespace std;
int N, E;
int E1[1000], E2[1000];
int visited[1000];
int adj[1000][1000];
stack<int>Stack;

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
    s.push(u);
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
    while(!s.empty())
    {
    	cout << s.top() << " ";
    	s.pop();
	}
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
    }
    topologicalSort();
    return 0;
}

/*
ip
6 6
6 3
6 1
5 1
5 2
3 4
4 2
op
6 5 3 4 2 1
*/
