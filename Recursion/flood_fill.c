#include<stdio.h>
int M[50][50];
int m, n;

int isSafe(int x, int y)
{
	return (x >=0 && x < m 
		&& y >= 0 && y < n);
}

void floodfillUtil(int x, int y, int prevC, int newC)
{
	if(!isSafe(x, y))
		return;
		
	if(M[x][y] != prevC)
		return;
		
	M[x][y] = newC;
	floodfillUtil(x+1, y, prevC, newC);
	floodfillUtil(x-1, y, prevC, newC);
	floodfillUtil(x, y+1, prevC, newC);
	floodfillUtil(x, y-1, prevC, newC);
}

void floodfill(int x, int y, int newC)
{
	int prevC = M[x][y];
	floodfillUtil(x, y, prevC, newC);
}

int main() 
{
	int i, j, x, y, newC;
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	scanf("%d%d%d", &x, &y, &newC);
	floodfill(x, y, newC);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
ip
8 8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 0 0 1 1 0 1 1
1 2 2 2 2 0 1 0
1 1 1 2 2 0 1 0
1 1 1 2 2 2 2 0
1 1 1 1 1 2 1 1
1 1 1 1 1 2 2 1
4 4 3
op
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 0 0 1 1 0 1 1
1 3 3 3 3 0 1 0
1 1 1 3 3 0 1 0
1 1 1 3 3 3 3 0
1 1 1 1 1 3 1 1
1 1 1 1 1 3 3 1
*/

