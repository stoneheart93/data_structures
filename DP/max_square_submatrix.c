#include<stdio.h>

int min(int a, int b, int c)
{
	return (a < b) ? ( a < c ? a : c) : (b < c ? b : c) ;
}

void maxSquareMat(int M[10][10], int m, int n)
{
	int i, j; 
	int S[m][n]; 
	int max_of_s, max_i, max_j;  
   
	for(i = 0; i < m; i++) 
		S[i][0] = M[i][0]; 
   
	for(j = 0; j < n; j++) 
    	S[0][j] = M[0][j]; 
       
	for(i = 1; i < m; i++) 
	{ 
    	for(j = 1; j < n; j++) 
    	{ 
			if(M[i][j] == 1)  
	        	S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1; 
	      	else
	        	S[i][j] = 0; 
    	}     
  	}  

	max_of_s = S[0][0]; 
	
	for(i = 1; i < m; i++) 
	{ 
    	for(j = 1; j < n; j++) 
    	{
			if(max_of_s < S[i][j]) 
      		{ 
		        max_of_s = S[i][j]; 
		        max_i = i;  
		        max_j = j; 
		    }         
    	}                  
 	}      
    
	for(i = max_i; i > max_i - max_of_s; i--) 
	{ 
    	for(j = max_j; j > max_j - max_of_s; j--) 
    	{ 
      		printf("%d ", M[i][j]); 
    	}   
    	printf("\n"); 
  	}   
}

int main() 
{
	int i, j, m, n;
	int M[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	maxSquareMat(M, m, n);
	return 0;
}

/*
ip
3 4
1 0 0 1
0 0 1 0
0 0 0 0
op
1 1 1 1
1 1 1 1
1 0 1 1
*/
