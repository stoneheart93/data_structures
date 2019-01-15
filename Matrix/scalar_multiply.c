#include<stdio.h>

void scalar_multiply(int M[10][10], int m, int n, int k)
{
	int i, j;
	  
   	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			M[i][j] *= k; 
		}
	}
}

int main() 
{
	int i, j, m, n, k;
	int M[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	scanf("%d", &k);
	scalar_multiply(M, m, n, k);
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

