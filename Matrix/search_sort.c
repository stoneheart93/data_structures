#include<stdio.h>

int search(int M[10][10], int n, int x)
{
	int i = 0, j = n-1;  
   	while(i < n && j >= 0)
   	{
    	if(M[i][j] == x)
      	{
        	printf("%d, %d", i, j);
         	return 1;
      	}
      	else if(M[i][j] > x)
        	j--;
      	else //  if M[i][j] < x
        	i++;
   	}
	return 0;  
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
	scanf("%d", &x);
	if(!search(M, n, x))
		printf("Not found");
	return 0;
}

/*
ip
4
10 20 30 40
15 25 35 45
27 29 32 48
32 33 39 50
29
op
2, 1
*/
