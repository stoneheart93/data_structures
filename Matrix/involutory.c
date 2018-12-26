/* The matrix M is said to be involutory matrix if and only if M * M = I */

#include<stdio.h>

void multiply(int A[10][10], int n, int C[10][10])
{
	int i, j, k;
	  
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

int involutory(int A[10][10], int n)
{
	int C[10][10];
	int i, j;
	multiply(A, n, C);
	
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			if(i == j && C[i][j] != 1)
				return 0;
			if(i != j && C[i][j] != 0)
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
	
	printf("%d", involutory(A, n));
	return 0;
}

