#include<stdio.h>

int lower(int M[10][10], int n)
{
	int i, j;
	  
   	for(i = 0; i < n; i++) 
	{
		for(j = i+1; j < n; j++) 
		{
			if(M[i][j] != 0)
				return 0;
		}
	}
	return 1;
}

int upper(int M[10][10], int n)
{
	int i, j;
	  
   	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < i; j++) 
		{
			if(M[i][j] != 0)
				return 0;
		}
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
	if(lower(M, n))
		printf("\nLower");
	else
		printf("\nNot lower");
		
	if(upper(M, n))
		printf("\nUpper");
	else
		printf("\nNot upper");
	
	return 0;
}

