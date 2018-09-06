#include<stdio.h>

int multiply(int A[10][10], int m, int n, int B[10][10], int p, int q, int C[10][10])
{
	int i, j, k = 0;
	  
   	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < q; j++) 
		{
			C[i][j] = 0; 
			for(k = 0; k < n; k++) 
			{
				C[i][j] += A[i][k] * B[k][j];
 			}
		}
	}
}

int main() 
{
	int i, j, m, n, p, q;
	int A[10][10], B[10][10], C[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &A[i][j]);
		}
	}
	scanf("%d%d", &p, &q);
	for(i = 0; i < p; i++) 
	{
		for(j = 0; j < q; j++) 
		{
			scanf("%d", &B[i][j]);
		}
	}
	if(n == p)
		multiply(A, m, n, B, p, q, C);
	else
	{
		printf("Matrix multiplication not possible");
		return 0;
	}
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < q; j++) 
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	return 0;
}

