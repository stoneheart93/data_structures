#include<stdio.h>

int N;
int visited[100][100];
int m[100][100];

int isSafe(int x, int y)
{
    return (x >= 1 && x <= N 
		&& y >= 1 && y <= N 
		&& !visited[x][y]
		&& m[x][y]);
}

int mazeUtil(int x, int y)
{
    if(x == N && y == N)
    {
		visited[x][y] = 1;
    	return 1;
    }
    
	if(isSafe(x, y))
    {
		visited[x][y] = 1;
		
		if(mazeUtil(x, y+1))
			return 1;
		
		if(mazeUtil(x+1, y))
			return 1;
		
		visited[x][y] = 0;
		return 0;
    }
    return 0;
}

void maze()
{
    memset(visited, 0, N*N);
	int i, j;
    
	if(mazeUtil(1,1))
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
	int i, j;
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
    {
		for(j = 1; j <= N; j++)
       	{
		   scanf("%d", &m[i][j]);
		}
	}
    maze();
    return 0;
}
