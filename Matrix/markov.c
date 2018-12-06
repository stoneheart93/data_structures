#include<stdio.h>

int markov(double M[10][10], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
    {
    	double sum = 0;   	
    	for(j = 0; j < n; j++)
        {
        	sum += M[i][j];
		}
		if(sum != 1)
			return 0;
	}
	return 1;
}
 
int main() 
{
	int i, j, m, n;
	double M[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%lf", &M[i][j]);
		}
	}
	printf("%d", markov(M, m, n));
	return 0;
}
