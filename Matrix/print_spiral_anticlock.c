#include<stdio.h>

void spiralPrintCounterClockwise(int M[10][10], int m, int n)
{
	int i, k = 0, l = 0;
    while(k < m && l < n)
    {
        for(i = k; i < m; i++)
            printf("%d ", M[i][l]);
        l++;
 
 		for(i = l; i < n; i++)
            printf("%d ", M[m-1][i]);
        m--;
 
        if(k < m)
        {
            for(i = m - 1; i >= k; i--)
                printf("%d ", M[i][n-1]);
            n--;
        }
 
        if(l < n)
        {
            for(i = n - 1; i >= l; i--)
                printf("%d ", M[k][i]);
            k++;    
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
	spiralPrintCounterClockwise(M, m, n);
	return 0;
}

/*
ip
3 3
1 2 3
4 5 6
7 8 9
op
1 4 7 8 9 6 3 2 5
*/
