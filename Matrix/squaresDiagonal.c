#include<stdio.h>

void squaresDiagonal(int M[10][10], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		printf("%d ", M[i][i] * M[i][i]);
	}
	printf("\n");
	for(i = 0; i < n; i++)
	{
		printf("%d ", M[i][n-1-i] * M[i][n-1-i]);
	}
}

int main() 
{
	int i, j, n;
	int M[10][10];
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	squaresDiagonal(M, n);
	
	return 0;
}

