#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}

void reverseColumns(int M[10][10], int n)
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

void transpose(int M[10][10], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			swap(&M[i][j], &M[j][i]);
		}
	}
}

void rotate180(int M[10][10], int n) 
{
	transpose(M, n);
	reverseColumns(M, n);
	transpose(M, n);
	reverseColumns(M, n);
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
	rotate180(M, n);
	for(i = 0; i < n; i++) 
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
3 
1 2 3
4 5 6
7 8 9
op
9 8 7
6 5 4
3 2 1
*/
