#include<stdio.h>

int horizontalSymmetry(int M[10][10], int m, int n)
{
	int i, j, k;
	
	for(i = 0, k = m - 1; i < m/2; i++, k--)
	{
		for(j = 0; j < n; j++)
		{
			if(M[i][j] != M[k][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

int verticalSymmetry(int M[10][10], int m, int n)
{
	int i, j, l;
	
	for(j = 0, l = n - 1; j < n/2; j++, l--)
	{
		for(i = 0; i < m; i++)
		{
			if(M[i][j] != M[i][l])
			{
				return 0;
			}
		}
	}
	return 1;
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

	if(horizontalSymmetry(M, m, n))
		printf("Horizontal Symmetry");
	else
		printf("Not horizontal symmetry");
		
	if(verticalSymmetry(M, m, n))
		printf("Vertical Symmetry");
	else
		printf("Not vertical symmetry");
	
	return 0;
}

