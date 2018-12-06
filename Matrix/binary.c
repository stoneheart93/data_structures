#include<stdio.h>

int binary(int M[10][10], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
    {
    	for(j = 0; j < n; j++)
        {
        	if(!(M[i][j] == 0 || M[i][j] == 1))
        		return 0;
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
	printf("%d", binary(M, m, n));
	return 0;
}
