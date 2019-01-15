#include<stdio.h>

int first(int a[], int low, int high)
{
	while(low < high)
	{
		int mid = low + (high - low)/2; 
		if( (mid == 0 || a[mid-1] == 0) && a[mid] == 1)
     		return mid; 
    	else if(a[mid] == 0)
    		low = mid + 1;
		else
			high = mid - 1;
	}
  	return -1;
}
 

int rowmax1(int M[10][10], int m, int n)
{
	int max_row_index = 0;

	int j = first(M[0], 0, n - 1);
    
	if (j == -1) 
    	j = n - 1;
 
	int i; 
    for(i = 1; i < m; i++)
    {
        while(j >= 0 && M[i][j] == 1)
        {
        	j = j - 1;  
        	max_row_index = i;  
		}
    }
    return max_row_index;
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
	printf("%d", rowmax1(M, m, n));
	return 0;
}

/*
ip
4 4
0 0 0 1 
0 1 1 1
0 0 0 0
1 1 1 1
op
3
*/
