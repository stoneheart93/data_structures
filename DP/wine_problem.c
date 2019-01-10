#include<stdio.h>
int DP[20][20];

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int wine_sale_util(int a[], int n, int start, int end)
{
	if(DP[start][end] != -1)
		return DP[start][end];
		
	int year = n - (end-start);
	
	if(start == end)
		return year * a[start];
	else
	{
		DP[start][end] = max( year*a[start] + wine_sale_util(a, n, start+1, end), 
							  year*a[end] + wine_sale_util(a, n, start, end-1) );
		return DP[start][end];	
	}	
}

int wine_sale(int a[], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			DP[i][j] = -1;
		}
	}
	
	return wine_sale_util(a, n, 0, n-1);
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", wine_sale(a,n));
    return 0;
}
