#include<stdio.h>
#define INIT_MAX 999999
 
int max(int a, int b) 
{ 
	return (a > b)? a: b; 
}
 
int eggDrop(int n, int k)
{
    int C[n + 1][k + 1];
    int res, i, j, x;
 
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= k; j++)
        {
        	if(j == 0)
        		C[i][j] = 0;
        	else if(j == 1)
        		C[i][j] = 1;
        	else if(i == 1)
        		C[i][j] = j;
        	else
        	{
            	C[i][j] = INIT_MAX;
            	for(x = 1; x <= j; x++)
            	{
                	res = 1 + max(C[i - 1][x - 1], C[i][j - x]);
                	if (res < C[i][j])
                    	C[i][j] = res;
                }
            }
        }
    }
 	return C[n][k];
}
 
int main()
{
    int n, k;
    printf("\nEnter no of eggs: ");
    scanf("%d", &n);
    printf("\nEnter no of floors: ");
    scanf("%d", &k);
    printf ("\nMinimum number of trials in worst case with %d eggs and %d floors is %d", n, k, eggDrop(n, k));
    return 0;
}

/*
ip
Enter no of eggs: 2
Enter no of floors: 36
op
Minimum number of trials in worst case with 2 eggs and 36 floors is 8
*/
