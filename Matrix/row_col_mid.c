#include<stdio.h>

void sumMidRowCol(int M[10][10], int m, int n)
{
	int row_sum = 0, col_sum = 0;
	
	int i, j;
	
	for(j = 0; j < n; j++) 
		row_sum += M[m/2][j];
	
	for(i = 0; i < m; i++)
		col_sum += M[i][n/2];
	
	printf("Row sum:%d Col sum:%d", row_sum, col_sum);		
}

int main() 
{
	int i, j, m, n;
	int M[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	
	sumMidRowCol(M, m, n);	
	return 0;
}

