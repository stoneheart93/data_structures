#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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
	transpose(M, n);
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
