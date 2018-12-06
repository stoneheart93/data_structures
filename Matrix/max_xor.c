#include<stdio.h>

int max(int a, int b)
{
	return (a > b) ? a: b;
}

int max_xor(int M[10][10], int n)
{
	int i, j;
	int maxXor = 0;
	
	for(i = 0; i < n; i++)
	{
		int r_xor = 0, c_xor = 0;
		for(j = 0; j < n; j++)
		{
			r_xor ^= M[i][j];
			c_xor ^= M[j][i];
		}
		
		maxXor = max(maxXor, max(r_xor, c_xor));
	}
	return maxXor;
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
	printf("%d", max_xor(M, n));
	return 0;
}

