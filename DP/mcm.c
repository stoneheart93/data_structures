#include<stdio.h>
#include<limits.h>

int MatrixChainOrder(int p[], int arr_size)
{
    int n = arr_size - 1;
    int DP[n][n];
    
    int i, j, k, L, q;
 
 	for(i = 1; i <= n; i++)
		DP[i][i] = 0;
 
    for(L = 2; L <= n; L++)
    {
        for(i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            DP[i][j] = INT_MAX;
            for(k = i; k < j; k++)
            {
                q = DP[i][k] + DP[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < DP[i][j])
                    DP[i][j] = q;
            }
        }
    }
 
    return DP[1][n];
}
 
int main()
{
    int a[10];
    int arr_size, i;
    scanf("%d", &arr_size);
    for(i = 0; i < arr_size; i++)
    	scanf("%d", &a[i]);
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(a, arr_size));
    return 0;
}

/*
ip
4
1 2 3 4
op
18
*/
