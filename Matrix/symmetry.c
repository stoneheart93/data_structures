#include<stdio.h>

int symmetry(int M[10][10], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
    {
    	for(j = i+1; j < n; j++)
        {
        	if(M[i][j] != M[j][i])
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
	printf("%d", symmetry(M, n));
	return 0;
}
