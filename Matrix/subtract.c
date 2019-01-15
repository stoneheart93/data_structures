#include<stdio.h>

void sub(int A[10][10], int B[10][10], int m, int n, int C[10][10])
{
	int i, j;
	  
   	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			C[i][j] = A[i][j] - B[i][j];
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
	if(m == p && n == q)
		sub(A, B, m, n, C);
	else
	{
		printf("Matrix addition not possible");
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

