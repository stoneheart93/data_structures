#include<stdio.h>

int maxSquare(int M[10][10], int n)
{
	int sum[m][n];
	
	sum[0][0] = M[0][0];
	
	// preprocess 1st row
	for(j = 1; j < n; j++)
		sum[0][j] = M[0][j] + sum[0][j-1];
		
	// preprocess 1st col
	for(i = 1; i < n; i++)
		sum[i][0] = M[i][0] + sum[i-1][0];
		
	// preprocess rest
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			sum[i][j] = sum[i][j-1] + sum[i-1][j] + M[i][j] - sum[i-1][j-1]; 
		}
	}
	
	for(i = k-1; i < n; i++)
	{
		for(j = k-1; j < n; j++)
		{
			total = sum[i][j];
			if (i - k >= 0)
				total = total - sum[i - k][j];
			if (j - k >= 0)
				total = total - sum[i][j - k];
			if (i - k >= 0 && j - k >= 0)
				total = total + sum[i - k][j - k];
				
			if(total > max_sum)
			{
				max_sum  = total;
				max_i = i;
				max_j = j;
			}
		}
	}
	
	
	for(i = max_i - k + 1; i < max_i; i++)
	{
		for(j = max_j - k + 1; j < max_j; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
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
	maxSquare(M, n);
	return 0;	
}
