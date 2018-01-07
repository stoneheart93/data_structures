#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}

void mirror_diagonal(int M[10][10], int n)
{
    int i, j;
	for(i = 0; i < n; i++)
	{
        for(j = 0; j <= i; j++) 
        {
            swap(&M[i][j], &M[j][i]);
		}
	}
}

int main() 
{
	int i, j, n;
	int M[10][10];
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	mirror_diagonal(M, n);
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
ip
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
op
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16
*/
