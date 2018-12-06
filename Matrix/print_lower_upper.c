#include<stdio.h>

void lower(int M[10][10], int n)
{
	int i, j;
	  
   	for(i = 0; i < n; i++) 
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

void upper(int M[10][10], int n)
{
	int i, j;
	  
   	for(i = 0; i < n; i++) 
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
	printf("Lower:\n");
	lower(M, n);
	printf("Upper:\n");
	upper(M, n);
	return 0;
}

