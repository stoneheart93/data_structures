#include<stdio.h>
#include<iostream>
using namespace std;
int mat[50][50];
int visited[50][50];
int N;
int row[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int col[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int isSafe(int x, int y)
{
    return (x >= 1 && x <= N && y >= 1 && y <= N && mat[x][y] && !visited[x][y]);
}

void DFS(int x, int y)
{
    visited[x][y] = 1;
    
    for(int k = 0; k < 8; k++)
    {
        int next_x = x + row[k];
        int next_y = y + col[k];
        if(isSafe(next_x, next_y))
            DFS(next_x, next_y);
    }
}

int countIslands()
{
	for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            visited[i][j] = 0;
        }
    }
            
    int count = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if (mat[i][j] && !visited[i][j]) 
            {                        
                DFS(i, j);     
                count++;
            }
		}
	}
    return count;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("%d\n",countIslands());
    return 0;
}
