#include<stdio.h>

int lower(int M[10][10], int m, int n)
{
	int i, j;
	  
   	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			if(i < j)
				printf("0 ");
			else
				printf("%d ", M[i][j]); 
		}
		printf("\n");
	}
}

int upper(int M[10][10], int m, int n)
{
	int i, j;
	  
   	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			if(i > j)
				printf("0 ");
			else
				printf("%d ", M[i][j]); 
		}
		printf("\n");
	}
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
	printf("Lower:\n")
	lower(M, m, n);
	printf("Upper:\n")
	upper(M, m, n);
	return 0;
}

