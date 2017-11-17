//Find difference between sums of two diagonals

#include<stdio.h>

int difference(int M[10][10], int n) //O(n)
{
	int i;
	int sum1 = 0, sum2 = 0;
	for(i = 0; i < n; i++)
	{
		sum1 += M[i][i];
		sum2 += M[i][n-1-i]; 
	}
	return abs(sum1 - sum2);
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
	printf("%d", difference(M, n));
	return 0;
}
