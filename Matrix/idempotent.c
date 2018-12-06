/* The matrix M is said to be idempotent matrix if and only if M * M = M */

#include<stdio.h>

int multiply(int A[10][10], int n, int C[10][10])
{
	int i, j, k = 0;
	  
   	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			C[i][j] = 0; 
			for(k = 0; k < n; k++) 
			{
				C[i][j] += A[i][k] * A[k][j];
 			}
		}
	}
}

int idempotent(int A[10][10], int n)
{
	int C[10][10];
	int i, j;
	multiply(A, n, C);
	
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			if(A[i][j] != C[i][j])
				return 0;
		}
	}
	return 1;
}

int main() 
{
	int i, j, n;
	int A[10][10];
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("%d", idempotent(A, n));
	return 0;
}

