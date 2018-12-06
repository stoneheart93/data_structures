#include<stdio.h>
#include<limits.h>

void maxRow(int M[10][10], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		int max = INT_MIN;
		for(j = 0; j < n; j++)
		{
			if(M[i][j] > max)
				max = M[i][j];
		}
		printf("\n%d", max);
	}
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
	
	maxRow(M, m, n);	
	return 0;
}

