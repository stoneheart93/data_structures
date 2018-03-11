#include<iostream>
#include<list>
using namespace std;
int mat[200][200];
int visited[200][200];
int N, M, X, Y;
int row[] = { -1, 0, 1, 0 };
int col[] = { 0, -1, 0, 1 };

struct queue_struct
{
	int x;
	int y;
	int count;
};

int isSafe(int x, int y)
{
	return (x >= 1 && x <= R && y >= 1 && y <= C && !mat[x][y] && !visited[x][y]);
}

int BFS(int src_x, int src_y, int dest_x, int dest_y)
{
	for (int i = 1; i <= N; i++)
		visited[i] = 0;

	list<queue_struct> queue;
	visited[src_x][src_y] = 1;
	queue_struct src = {src_x, src_y,0};
    queue.push_back(src); 

	while (!queue.empty())
	{
		queue_struct U = queue.front();
        int p_x = U.x;
		int p_y = U.y;
		
		int count = U.count;
		queue.pop_front();
		
		if(p_x == )
			return count;
		
    	for(int v = u + 1; v <= (u + 6) && v <= N; v++)
		{
			if (!visited[v])
			{               
                visited[v] = 1;
                int next_v;   
                if(moves[v] != -1)
					next_v = moves[v];
				else
					next_v = v;
				queue_struct next_V = {next_v, count + 1};
				queue.push_back(next_V);
			}
		}
	}
}

int main()
{
	for (int i = 1; i<=N; i++)
		moves[i] = -1;

	// Ladders
	moves[3] = 22;
	moves[5] = 8;
	moves[11] = 26;
	moves[20] = 29;

	// Snakes
	moves[27] = 1;
	moves[21] = 9;
	moves[17] = 4;
	moves[19] = 7;

	cout << "Min Dice throws required is " << getMinDiceThrows();

	return 0;
}
