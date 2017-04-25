#include<iostream>
using namespace std;
int N, E;
int E1[1000], E2[1000];
int adj[1000][1000];

int countTriangle(int isDirected)
{
	int count = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			for(int k = 1; k <= N; k++)
			{
				if(adj[i][j] && adj[j][k] && adj[k][i])
					count++;
			}
		}
	}
	isDirected ? count /= 3 : count /= 6;
	return count;
}

int main()
{
	int isDirected;
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d", &E1[i], &E2[i]);
    	
    scanf("%d", &isDirected);
        
	for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            adj[i][j] = 0;
        }
    }
    for(int i = 1; i <= E; i++)
    {
    	if(isDirected)
        	adj[E1[i]][E2[i]] = 1;
        else
        {
        	adj[E1[i]][E2[i]] = 1;
        	adj[E2[i]][E1[i]] = 1;     	
		}
    }
    cout << "No of traingles " << countTriangle(isDirected);
    return 0;
}

/*
ip
4 5
1 3
2 1
2 4
3 2
4 3
1
op
No of traingles 2
*/
