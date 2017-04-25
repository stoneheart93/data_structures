#include<iostream>
#include<list>
using namespace std;

char mat[200][200];
int output[200][200];
int N, M, X, Y;
int row[] = { -1, 0, 1, 0 };
int col[] = { 0, -1, 0, 1 };

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

void BFS() 
{
	list<queue_struct> queue;
	
	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			output[i][j] = -1;
			
			if(mat[i][j] == 'G')
			{
				output[i][j] = 0;
				queue_struct guard = {i, j, 0};
				queue.push_back(guard);
			}
		}
	}
	

	while (!queue.empty()) 
	{
		queue_struct u = queue.front();
		int x = u.x;
		int y = u.y;
		int dist = u.dist;
		queue.pop_front();
		
		for(int k = 0; k < 4; k++) 
		{	
			int next_x = x + row[k];
			int next_y = y + col[k];
			if (isSafe(next_x, next_y)) 
			{
				output[next_x][next_y] = dist + 1;
				queue_struct temp = {next_x, next_y, dist + 1};
				queue.push_back(temp);
			}
		}
	}
}

void findDist() 
{
	BFS();
	for (int i = 1; i <= M; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{	
			printf("%d ", output[i][j]);
		}
	}
	printf("\n");
}
int main() 
{
	int i, j;
	scanf("%d%d", &M, &N);
	for (i = 1; i <= M; i++) 
	{
		for (j = 1; j <= N; j++) 
		{
			scanf(" %c", &mat[i][j]);
		}
	}
	findDist();
	return 0;
}

