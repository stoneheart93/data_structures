#include<iostream>
#include<queue>
using namespace std;
int N = 30;
int visited[30];
int moves[30];

struct queue_struct
{
	int x;
	int count;
};

int getMinDiceThrows()
{
	for(int i = 1; i <= N; i++)
		visited[i] = 0;

	queue<queue_struct> q;
	visited[1] = 1;
	queue_struct src = {1,0};
    q.push_back(src); 

	while(!q.empty())
	{
		queue_struct U = q.front();
        int u = U.x; 
		int count = U.count;
		q.pop();
		
		if(u == N)
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
				q.push(next_V);
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
