#include<stdio.h>
#include<algorithm>
using namespace std;

void row_sort(int M[10][10], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		sort(M[i], M[i] + n);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void transpose(int M[10][10], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = i+1; j < n; j++)
			swap(&M[i][j], &M[j][i]);
	}
}

void row_column_sort(int M[10][10], int m, int n)
{
	row_sort(M, m, n);
	transpose(M, m, n);
	row_sort(M, m, n);
	transpose(M, m, n);
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
	row_column_sort(M, m, n);
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

