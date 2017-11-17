//Circular Matrix (Construct a matrix with numbers 1 to m*n in spiral way)

#include<stdio.h>

void spiralFill(int M[10][10], int m, int n) // O(m*n)
{
	int val = 1;
	int i, k = 0, l = 0;
    while(k < m && l < n)
    {
        for(i = l; i < n; i++)
            M[k][i] = val++;
        k++;
 
        for(i = k; i < m; i++)
            M[i][n-1] = val++;
        n--;
 
        if(k < m)
        {
            for(i = n - 1; i >= l; i--)
            	M[m-1][i] = val++;
            m--;
        }
 
        if(l < n)
        {
            for(i = m - 1; i >= k; i--)
                M[i][l] = val++;
            l++;    
        }        
    }
}

int main() 
{
	int i, j, m, n;
	int M[10][10];
	scanf("%d%d", &m, &n);
	spiralFill(M, m, n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			printf("%d\t", M[i][j]);
		}
		printf("\n");
	}
	return 0;
}

