#include<stdio.h>

void symmetry(int M[10][10], int m, int n)
{
	int i, k, j, l;
	int horizontal = 1, vertical = 1;
	
	for(i = 0, k = m - 1; i < m/2; i++, k--)
	{
		for(j = 0; j < n; j++)
		{
			if(M[i][j] != M[k][j])
			{
				horizontal = 0;
				break;
			}
		}
	}
	
	for(j = 0, l = n - 1; j < n/2; j++, l--)
	{
		for(i = 0; i < m; i++)
		{
			if(M[i][j] != M[i][l])
			{
				vertical = 0;
				break;
			}
		}
	}
	
	if(horizontal && vertical)
		printf("Both");
	else if(horizontal && !vertical)
		printf("Horizontal");
	else if(!horizontal && !vertical)
		printf("Vertical");
	else
		printf("No");
		
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
	symmetry(M, m, n);
	return 0;
}

