#include<stdio.h>
#include<algorithm>
using namespace std;

void row_sort(int M[10][10], int n)
{
	for(int i = 0; i < n; i++)
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
void transpose(int M[10][10], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
			swap(&M[i][j], &M[j][i]);
	}
}

void row_column_sort(int M[10][10], int n)
{
	row_sort(M, n);
	transpose(M, n);
	row_sort(M, n);
	transpose(M, n);
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
	row_column_sort(M, n);
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

