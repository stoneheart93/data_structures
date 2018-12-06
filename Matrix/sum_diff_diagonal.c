#include<stdio.h>

void sumDiffDiagonal(int M[10][10], int n)
{
	int i, j;
	int primary = 0, secondary = 0;
	for(i = 0; i < n; i++)
	{
		primary += M[i][i];
		secondary += M[i][n-1-i];
	}
	printf("\nSum: Primary: %d Secondary: %d", primary, secondary);
	printf("\nAbsolute Difference between them: %d", abs(primary - secondary));
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
	sumDiffDiagonal(M, n);
	return 0;
}

