#include<stdio.h>

int sumexc(int M[10][10], int m, int n, int pos_x, int pos_y)
{
	int i, j, sum = 0;  
   	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			sum += M[i][j]; 
		}
	}
	return sum - M[pos_x][pos_y];  
}

int main() 
{
	int i, j, m, n, pos_x, pos_y;
	int M[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	scanf("%d%d", &pos_x, &pos_y);
	printf("%d",sumexc(M, m, n, pos_x, pos_y));
	return 0;
}

