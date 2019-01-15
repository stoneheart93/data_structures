#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}

void reverseRows(int M[10][10], int n)
{
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		for(j = 0, k = n - 1; j < k; j++, k--)
		{
			swap(&M[i][j], &M[i][k]);
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

void rotate90(int M[10][10], int n) //anti-clockwise
{
	reverseRows(M, n);
	transpose(M, n);
}

/*void rotate90(int M[10][10], int n) //clockwise
{
	transpose(M, n);
	reverseRows(M, n);
}*/

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
	rotate90(M, n);
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
7 4 1
8 5 2
9 6 3
*/
