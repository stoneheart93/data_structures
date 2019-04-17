#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int mat[50][50];
int dist[50][50];
int M, N;
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, -1, 0, 1};

struct queue_struct
{
	int x;
	int y;
};

int isSafe(int x, int y)
{
    return (x >= 1 && x <= M && y >= 1 && y <= N);
}

void nearest1()
{
	queue<queue_struct> q;
	
    for(int i = 1; i <= M; i++)
    {
    	for(int j = 1; j <= N; j++)
    	{
    		dist[i][j] = INT_MAX;
    		if(mat[i][j])
    		{
    			dist[i][j] = 0;
    			queue_struct d = {i, j};
    			q.push(d);
			}
		}
	}
	
	while(!q.empty())
	{
		queue_struct U = q.front();
		int x = U.x;
		int y = U.y;
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int next_x = x + row[k];
			int next_y = y + col[k];
			
			if(isSafe(next_x, next_y) && dist[x][y] + 1 < dist[next_x][next_y])
			{
				dist[next_x][next_y] = dist[x][y] + 1;			
				queue_struct next_V = {next_x, next_y};
				q.push(next_V);
			}
		}
	}
}

int main()
{
    scanf("%d%d", &M, &N);
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    nearest1();
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
