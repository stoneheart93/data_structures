#include<stdio.h>

void rotate_elements(int M[10][10], int m, int n)
{
	int i, k = 0, l = 0;
	int prev, curr;
    while(k < m - 1 && l < n - 1)
    {
    	prev = M[k+1][l];
    	for(i = l; i < n; i++)
       	{
       		curr = M[k][i];
        	M[k][i] = prev;
        	prev = curr;
        }
		k++;
 
        for(i = k; i < m; i++)
        {
        	curr = M[i][n-1];
        	M[i][n-1] = prev;
        	prev = curr;
        }
		n--;
 
        if(k < m)
        {
            for(i = n - 1; i >= l; i--)
            {
            	curr = M[m-1][i];
	        	M[m-1][i] = prev;
	        	prev = curr;
	        }
		    m--;
        }
 
        if(l < n)
        {
            for(i = m - 1; i >= k; i--)
            {
            	curr = M[i][l];
	        	M[i][l] = prev;
	        	prev = curr;
	        }    
            l++;    
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
	rotate_elements(M, m, n);
	printf("\n");
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

/*
ip
3 3
1 2 3
4 5 6
7 8 9
op
4 1 2
7 5 3
8 9 6
*/
