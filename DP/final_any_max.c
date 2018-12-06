#include<stdio.h>
char M[50][50];
int DP[50][50][2];
int m, n;

int isSafe(int x, int y)
{
	return (x >= 0 && x < m
		&& y >= 0 && y < n);
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int getMaxUtil(int x, int y, int dir)
{	
	if(!isSafe(x, y) || M[x][y] == '#')
		return 0;
		
	if(DP[x][y][dir] != -1)
		return DP[x][y][dir];
		 
	int temp = (M[x][y] == 'C') ? 1 : 0;
		
	if(dir == 1) // right
		DP[x][y][dir] = temp + max(getMaxUtil(x, y+1, 1), 
								  getMaxUtil(x+1, y, 0));
	else
		DP[x][y][dir] = temp + max(getMaxUtil(x, y-1, 0), 
								  getMaxUtil(x+1, y, 1));
	return DP[x][y][dir];
}

int getMax()
{
	int i, j, k;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < 2; k++)
			{
				DP[i][j][k] = -1;
			}
		}
	}
	
	return getMaxUtil(0, 0, 1);
}

int main() 
{
	int i, j;
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf(" %c", &M[i][j]);
		}
	}
	printf("%d", getMax());
	return 0;
}
