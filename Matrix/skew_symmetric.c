/*
A Skew Symmetric Matrix or Anti-Symmetric Matrix is a square matrix whose transpose is negative to that of the original matrix. 
*/

#include<stdio.h>

void transpose(int transpose_M[10][10], int M[10][10], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
    {
    	for(j = 0; j < n; j++)
            transpose_M[j][i] = M[i][j];
    }
}
 
int check(int transpose_M[10][10], int M[10][10], int n)
{
	int i, j;
    for(i = 0; i < n; i++)
    {
    	for(j = 0; j < n; j++)
    	{
    		if(M[i][j] != -transpose_M[i][j])
                return 0;
		}
	}       
    return 1;
}

int main() 
{
	int i, j, n;
	int M[10][10], transpose_M[10][10];
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	transpose(transpose_M, M, n);
	if(check(transpose_M, M, n))
		printf("Skew symmetric");
	else
		printf("No");
	return 0;
}
