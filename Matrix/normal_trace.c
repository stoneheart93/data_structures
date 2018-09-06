/*
Normal of a matrix is defined as square root of sum of squares of matrix elements.
Trace of a n x n square matrix is sum of diagonal elements.
*/

#include<stdio.h>

int normal(int M[10][10], int n) // O(n*n)
{
	int sum = 0;
	int i, j;
    for(i = 0; i < n; i++)
    {
    	for(j = 0; j < n; j++)
    		sum += M[i][j] * M[i][j];
	}    
    return sqrt(sum);
}
int trace(int M[10][10], int n) // O(n)
{
	int sum = 0, i;
    for(i = 0; i < n; i++)
        sum += M[i][i];
    return sum;
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
	printf("Normal: %d  Trace: %d", normal(M, n), trace(M, n));
	return 0;
}
