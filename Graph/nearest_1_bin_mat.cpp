#include<iostream>
#include<list>
#define INIT_MAX 9999999
using namespace std;

int mat[200][200];
int dist[200][200];
int N, M, X, Y;
int row[] = { -1, 0, 1, 0 };
int col[] = { 0, -1, 0, 1 };

struct queue_struct 
{
	int x;
	int y;
};

int isSafe(int x, int y) 
{
	return (x >= 1 && x <= M && y >= 1 && y <= N );
}

void nearest1() 
{
	list<queue_struct> queue;
	
	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			dist[i][j] = INIT_MAX;
			
			if(mat[i][j] == 1)
			{
				dist[i][j] = 0;
				queue_struct d = {i, j};
				queue.push_back(d);
			}
		}
	}
	

	while (!queue.empty()) 
	{
		queue_struct u = queue.front();
		int x = u.x;
		int y = u.y;
		queue.pop_front();
		
		for(int k = 0; k < 4; k++) 
		{	
			int next_x = x + row[k];
			int next_y = y + col[k];
			if (isSafe(next_x, next_y) &&  dist[next_x][next_y] > dist[x][y] + 1)
			{
				dist[next_x][next_y] = dist[x][y] + 1;
				queue_struct temp = {next_x, next_y};
				queue.push_back(temp);
			}
		}
	}
}

int main() 
{
	int i, j;
	scanf("%d%d", &M, &N);
	for (i = 1; i <= M; i++) 
	{
		for (j = 1; j <= N; j++) 
		{
			scanf("%d", &mat[i][j]);
		}
	}
	nearest1();
	for (i = 1; i <= M; i++) 
	{
		for (j = 1; j <= N; j++) 
		{
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
ip
3 4
0 0 0 1
0 0 1 1
0 1 1 0
op
3 2 1 0
2 1 0 0
1 0 0 1
*/

