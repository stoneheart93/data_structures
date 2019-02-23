#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lrs(char* X, int n)
{
    int L[n + 1][n + 1];
    int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(X[i - 1] == X[j - 1] && i != j)
            	L[i][j] = L[i - 1][j - 1] + 1;
            else
            	L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[n][n];
}

int main()
{
	char X[30];
	scanf("%s", X);
	printf("%d", lrs(X, strlen(X)));  
  	return 0;
}

