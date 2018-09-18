#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcstr(char* X, char* Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;
    int max = 0;
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(X[i - 1] == Y[j - 1])
            {
            	L[i][j] = L[i - 1][j - 1] + 1;
            	if(L[i][j] > max)
					max = L[i][j];
			}
            else
            	L[i][j] = 0;
        }
    }
    return max;;
}

int main()
{
	char X[30], Y[30];
	scanf("%s", X);
	scanf("%s", Y);
	printf("%d", lcstr(X, Y, strlen(X), strlen(Y)));  
  	return 0;
}

