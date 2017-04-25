#include<iostream>
#include<list>
using namespace std;
int N, E;
int E1[10000], E2[10000];
int adj[1000][1000];
int visited[1000];

int isReachable(int s, int d)
{
	if(s == d)
		return 1;
	list<int> queue;
	visited[s] = 1;
	queue.push_back(s);
	while(!queue.empty())
	{
		int u = queue.front();
		queue.pop_front();
		for(int v = 1; v <= N; v++)
		{
			if(adj[u][v])
			{
				if(v == d)
					return 1;
				if(!visited[v])
				{
					visited[v] = 1;
					queue.push_back(v);
				}
			}
		}
	}
	return 0;
}

void call_isReachable(int s, int d)
{
	for(int i = 1; i <= N; i++)
		visited[i] = 0;
	if(isReachable(s, d))
		cout << "There is a path from " << s << " to " << d;
	else
		cout << "No path";
}

int main()
{
	int s, d;
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d", &E1[i], &E2[i]);
    scanf("%d%d", &s, &d);
        
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
    call_isReachable(s, d);
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
2 4
op
There is a path from 2 to 4
*/
