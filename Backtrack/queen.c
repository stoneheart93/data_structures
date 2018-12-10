#include<stdio.h>
int N = 4;
int visited[100][100];

int isSafe(int row, int col)
{
	int i, j;
	
    for(j = 1; j < col; j++)
	{
	    if(visited[row][j]) 
        	return 0;
	}
  
    for(i = row, j = col; i >= 1 && j >= 1; i--, j--)
	{
	    if(visited[i][j]) 
            return 0;
	}
  
    for(i = row, j = col; j >= 1 && i <= N; i++, j--)
	{
	    if(visited[i][j]) 
            return 0;
	}
	return 1;
}

int queenUtil(int col)
{
    if(col > N)
    	return 1;
    
	int i;
	for(i = 1; i <= N; i++)
    {
        if(isSafe(i, col))
        {
        	visited[i][col] = 1;
            if(queenUtil(col+1))
                return 1;
           	visited[i][col] = 0;
        }
    }
    return 0;
}
void queen()
{
    memset(visited, 0, N*N);
	int i, j;
    
	if(queenUtil(1))
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
    queen();
    return 0;
}
