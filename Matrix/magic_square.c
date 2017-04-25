#include<stdio.h>
#include<string.h>
 
void generateSquare(int n)
{
	int magicSquare[n][n];
 	memset(magicSquare, 0, sizeof(magicSquare));
 
    int i = n/2;
    int j = n-1;
    int num;
 
    for(num = 1; num <= n*n; )
    {
        if(i == -1 && j == n) 
        {
            j = n-2;
            i = 0;
        }
        else
        {
            if(i == -1)
            	i = n - 1;
            if(j == n)
                j = 0;
        }
        if(magicSquare[i][j]) 
        {
        	i++;
            j = j - 2;
            continue;
        }
        else
        	magicSquare[i][j] = num++; 
        i--; 
		j++;
	}
	
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", magicSquare[i][j]);
        }
		printf("\n");
    }
}
 
int main()
{
    int n = 7; // Works only when n is odd
    generateSquare(n);
    return 0;
}
