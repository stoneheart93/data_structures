#include<stdio.h>

int countNegative(int M[10][10], int n)
{
	int i = 0, j = n-1;
	int count = 0;  
   	while(i < n && j >= 0)
   	{
   		if(M[i][j] < 0)
      	{
      		count += (j + 1);
        	i++;
		}
		else
			j--;
	}
	return count;  
}

int main() 
{
	int i, j, n, x;
	int M[10][10];
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	
	printf("%d", countNegative(M, n));
	return 0;
}

