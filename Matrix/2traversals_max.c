#include<stdio.h>
int M[50][50];
int DP[50][50][50];
int m, n;

int isSafe(int x, int y1, int y2)
{
	return (x >= 0 && x < m
		&& y1 >= 0 && y1 < n
		&& y2 >= 0 && y2 < n 
		&& !DP[x][y1][y2]);
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int max9(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	return max(max(max(max(a, b), max(c, d)), 
			   max(max(e, f), max(g, h))), i);
}

int getMaxUtil(int x, int y1, int y2)
{
	if(x == m - 1 && y1 == 0 && y2 == n - 1)
		return (y1 == y2) ? M[x][y1] : M[x][y1] + M[x][y2];
		
	if(x == m - 1) //necessary as both the traversals are at the last row but not at their destination
		return -1;
	
	if(isSafe(x, y1, y2))
	{
		int temp = (y1 == y2) ? M[x][y1] : M[x][y1] + M[x][y2];
		
		DP[x][y1][y2] = temp + max9(getMaxUtil(x+1, y1, y2), 
								   getMaxUtil(x+1, y1, y2+1),
								   getMaxUtil(x+1, y1, y2-1),
								    
								   getMaxUtil(x+1, y1+1, y2), 
								   getMaxUtil(x+1, y1+1, y2+1), 
								   getMaxUtil(x+1, y1+1, y2-1),
								   
								   getMaxUtil(x+1, y1-1, y2), 
								   getMaxUtil(x+1, y1-1, y2+1), 
								   getMaxUtil(x+1, y1-1, y2-1));
								   
	}
	return DP[x][y1][y2];
}

int getMax()
{
	int i, j, k;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				DP[i][j][k] = 0;
			}
		}
	}
	
	return getMaxUtil(0, 0, n-1);
}


int main() 
{
	int i, j;
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	printf("%d", getMax());
	return 0;
}
