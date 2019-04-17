#include<iostream>
#include<queue>
using namespace std;
char mat[50][50];
int output[50][50];
int M, N;
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, -1, 0, 1};

struct queue_struct
{
	int x;
	int y;
	int dist;
};

int isSafe(int x, int y)
{
    return (x >= 1 && x <= M && y >= 1 && y <= N && mat[x][y] == 'O' && output[x][y] == -1);
}

void shortestDistance()
{
	queue<queue_struct> q;
	
	for(int i = 1; i <= M; i++)
    {
    	for(int j = 1; j <= N; j++)
    	{
    		output[i][j] = -1;
    		if(mat[i][j] == 'G')
    		{
    			output[i][j] = 0;
    			queue_struct guard = {i, j, 0};
    			q.push(guard);
			}
		}
	}
	
	while(!q.empty())
	{
	
		queue_struct U = q.front();
		int x = U.x;
		int y = U.y;
		int dist = U.dist;
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int next_x = x + row[k];
			int next_y = y + col[k];
			
			if(isSafe(next_x, next_y))
			{
				output[next_x][next_y] = dist + 1;			
				queue_struct next_V = {next_x, next_y, dist+1};
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
            scanf(" %c",&mat[i][j]);
        }
    }
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }
    shortestDistance();
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            printf("%d ",output[i][j]);
        }
        printf("\n");
    }
    return 0;
}

