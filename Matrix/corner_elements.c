#include<stdio.h>

void corner_elements(int M[10][10], int m, int n)
{
	printf("%d %d %d %d ", M[0][0], M[0][n-1], M[m-1][0], M[m-1][n-1]);
	printf("%d", M[0][0] + M[0][n-1] + M[m-1][0] + M[m-1][n-1]);
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
	corner_elements(M, m, n);
	return 0;
}

