#include<stdio.h>
 
int subsetSum(int sum, int a[], int n)
{
	int C[n + 1][sum + 1];
	int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= sum; j++)
        {
            if(i == 0)
                C[i][j] = 0;  
			else if(j == 0)
                C[i][j] = 1;
            else if(a[i] > j)
            	C[i][j] = C[i-1][j];
            else
            	C[i][j] = C[i-1][j] || C[i-1][j-a[i]];
        }
    }
    return C[n][sum];
}

int main()
{
    int sum, n;
	int a[100];
	int i;
	scanf("%d", &sum);
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d", subsetSum(sum, a, n));
    return 0;
}


