#include<stdio.h>

int isDiagonal(int M[10][10], int n)
{
	int i, j;
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			if(i != j && M[i][j] != 0)
				return 0;
		}
	}
	return 1;
}

int isScalar(int M[10][10], int n)
{
	int i, j;
	int element = M[0][0];
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			if(i != j && M[i][j] != 0)
				return 0;
			if(i == j && M[i][j] != element)
				return 0;
		}
	}
	return 1;
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
	
	printf("\n%d", isDiagonal(M, n));
	printf("\n%d", isScalar(M, n));
	return 0;
}

