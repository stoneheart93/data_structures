#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}

void reverseRows(int M[10][10], int m, int n)
{
	int i, j, k;
	for(i = 0; i < m; i++)
	{
		for(j = 0, k = m - 1; j < k; j++, k--)
		{
			swap(&M[i][j], &M[i][k]);
		}
	}
}

void reverseColumns(int M[10][10], int m, int n)
{
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		for(j = 0, k = n - 1; j < k; j++, k--)
		{
			swap(&M[j][i], &M[k][i]);
		}
	}
}

void transpose(int M[10][10], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = i; j < n; j++)
		{
			swap(&M[i][j], &M[j][i]);
		}
	}
}

void rotate180(int M[10][10], int m, int n) 
{
	transpose(M, m, n);
	reverseColumns(M, m, n);
	transpose(M, m, n);
	reverseColumns(M, m, n);
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
	rotate180(M, m, n);
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

/*
ip
3 3
1 2 3
4 5 6
7 8 9
op
9 8 7
6 5 4
3 2 1
*/
