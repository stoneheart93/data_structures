#include<stdio.h>

int isMagic(int M[10][10], int n)
{
	int i, j;
	
	int sum = 0;
	for(i = 0; i < n; i++)
		sum += M[i][i];
		
	for(i = 0; i < n; i++)
	{
		int row_sum = 0;
		for(j = 0; j < n; j++)
			row_sum += M[i][j];
		if(row_sum != sum)
			return 0;
	}
	
	for(j = 0; j < n; j++)
	{
		int col_sum = 0;
		for(i = 0; i < n; i++)
			col_sum += M[i][j];
		if(col_sum != sum)
			return 0;
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
	if(isMagic(M, n))
		printf("\nMagic Square");
	else
		printf("\nNot magic square");
		
	return 0;
}

