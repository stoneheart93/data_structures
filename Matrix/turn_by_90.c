#include<stdio.h>

void rotate(int S[10][10], int D[10][10], int m, int n)
{
	int r, c;
	for(r = 0; r < m; r++)
	{
		for(c = 0; c < n; c++)
		{
			D[c][m - 1 - r] = S[r][c];
		}
	}
}


int main() 
{
	int i, j, m, n;
	int S[10][10], D[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &S[i][j]);
		}
	}
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			D[i][j] = 0;
		}
	}
	rotate(S, D, m, n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
ip
3 3
1 2 3
4 5 6
7 8 9
op
7 4 1
8 5 2
9 6 3
*/
