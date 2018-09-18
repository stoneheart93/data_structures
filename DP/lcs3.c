#include<stdio.h>
#include<string.h>

int max(int a, int b, int c)
{
	if(a > b)
    	return (a > c)? a : c;
    else
    	return (b > c)? b : c;
}

int lcs(char* X, char* Y, char* Z, int m, int n, int p)
{
    int L[m + 1][n + 1][p + 1];
    int i, j, k;
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
        	for(k = 0; k <= n; k++)
        	{
	            if(i == 0 || j == 0 || k == 0)
	                L[i][j][k] = 0;
	            else if(X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1])
	            	L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
	            else
	            	L[i][j][k] = max(L[i - 1][j][k], L[i][j - 1][k], L[i][j][k - 1]);
	    	}
        }
    }
    return L[m][n][p];
}

int main()
{
	char X[30], Y[30], Z[30];
	scanf("%s", X);
	scanf("%s", Y);
	scanf("%s", Z);
	printf("%d", lcs(X, Y, Z, strlen(X), strlen(Y), strlen(Z)));  
  	return 0;
}

