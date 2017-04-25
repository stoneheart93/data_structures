#include<stdio.h>
#define INIT_MAX 999999

int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
 
 	for(i = 1; i < n; i++)
		m[i][i] = 0;
 
    for(L = 2; L < n; L++)
    {
        for(i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INIT_MAX;
            for(k = i; k < j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n-1];
}
 
int main()
{
    int a[10];
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    	scanf("%d", &a[i]);
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(a, n));
    return 0;
}

/*
ip
4
1 2 3 4
op
18
*/
