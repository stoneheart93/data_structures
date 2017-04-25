#include<stdio.h>
 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
}
 
int knapsack(int W, int n, int wt[], int val[])
{
   int C[n + 1][W + 1];
   int i, j;
   
   for(i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
	   		if (i == 0 || j == 0)
		   		C[i][j] = 0;
            else if (wt[i] > j)
        		C[i][j] = C[i - 1][j];
			else
				C[i][j] = max(C[i - 1][j], val[i] + C[i - 1][j - wt[i]]);        
		}
   }
   return C[n][W];
}
 
int main()
{
	int W, n, i;
	int wt[20], val[20];
	printf("\nEnter the capacity of knapsack: ");
	scanf("%d", &W);
	printf("\nEnter the no. of items: ");
	scanf("%d", &n);
	printf("\nEnter the weight and value of the items: \n");
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &wt[i]);
		scanf("%d", &val[i]);
	}
	printf("%d", knapsack(W, n, wt, val));
    return 0;
}

/*
ip
Enter the capacity of knapsack: 50
Enter the no. of items: 3
Enter the weight and value of the items:
10 60
20 100
30 120
op
220
*/
