#include<stdio.h>
#include<queue>
using namespace std;
int n;
int visited[300][300];

int row[6] = {0, 2, 2, 0, -2, -2};
int col[6] = {-2, -1, 1, 2, 1, -1};

struct queue_struct
{
    int x, y, count;
};

int isSafe(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]);
}

int BFS(int src_x, int src_y, int dest_x, int dest_y)
{
    queue<queue_struct> q;
    queue_struct src = {src_x, src_y, 0};
    q.push(src);
    visited[src_x][src_y] = 1;

    while(!q.empty())
    {
        queue_struct u = q.front();
        int x = u.x;
        int y = u.y;
        int count = u.count;
        q.pop();

        if(x == dest_x && y == dest_y)
            return count;

        for(int k = 0; k < 6; k++)
        {
            int next_x = x + row[k];
            int next_y = y + col[k];

            if(isSafe(next_x, next_y))
            {
                queue_struct next_V = {next_x, next_y, count + 1};
                q.push(next_V);
            }
        }
    }
    return -1;
}

int main()
{
    int src_x, src_y, dest_x, dest_y;
    
    scanf("%d", &n);
    scanf("%d%d%d%d", &src_x, &src_y, &dest_x, &dest_y);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            visited[i][j] = 0;
        }
    }
    printf("%d", BFS(src_x, src_y, dest_x, dest_y));
    return 0;
}
