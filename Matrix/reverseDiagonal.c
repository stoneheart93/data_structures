#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverseDiagonal(int M[10][10], int n)
{
	int i = 0, j = n;
	
	while(i < j)
	{
		swap(&M[i][i], &M[j - 1][j - 1]);
		swap(&M[i][j - 1], &M[j - 1][i]);
		i++;
		j--;
	}
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
	reverseDiagonal(M, n);
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

