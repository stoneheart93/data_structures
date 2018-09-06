#include<stdio.h>
#include<algorithm>
using namespace std;

int sort(int M[10][10], int m, int n)
{
	int temp[m*n];
	int i, j, k = 0;
	  
   	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			temp[k++] = M[i][j]; 
		}
	}
	sort(temp, temp + k);

	k = 0;
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			M[i][j] = temp[k++]; 
		}
	}
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
	sort(M, m, n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	return 0;
}

