#include<stdio.h>
int N = 8;
int visited[100][100];
int row[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int isSafe(int x, int y)
{
    return (x >= 1 && x <= N 
		&& y >= 1 && y <= N 
		&& !visited[x][y]);
}

int knightUtil(int x, int y, int count)
{
    visited[x][y] = count;
    if(count == N*N - 1)
    	return 1;
    
	int k;
	for(k = 0; k < 8; k++)
    {
        int next_x = x + row[k];
        int next_y = y + col[k];
        if(isSafe(next_x, next_y))
        {
            if(knightUtil(next_x, next_y, count+1))
                return 1;
        }
    }
    visited[x][y] = 0;
    return 0;
}
void knight()
{
    memset(visited, 0, N*N);
	int i, j;
    
	if(knightUtil(1,1,0))
    {
    	for(i = 1; i <= N; i++)
        {
			for(j = 1; j <= N; j++)
            {
            	printf("%d ",visited[i][j]);
            }
            printf("\n");
        }
    }
}   
              
int main()
{
    knight();
    return 0;
}
