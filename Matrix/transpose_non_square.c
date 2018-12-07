/*
ol = or * n + oc
nl = nr * m + nc

since nr = oc and nc = or
nl = oc * m + or

ol = or * n + oc
Multiplying by m
ol * m = or * n * m + oc * m
	   = or * size + nl - or
	   = or * (size-1) + nl
	   
nl = ol * m - or * (size-1) 

Since they are all less than size - 1,

nl mod (size-1) = [ol * m  % (size-1)] - [or * (size-1) % (size-1)]
nl = (ol*m) % (size-1)
*/


#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void transpose(int A[], int m, int n)
{
	int size = m * n;
	int cycle;
	int ol = 1, nl; 
	
	int visited[size];
	visited[0] = visited[size-1] = 1;
	
	while(ol < size-1)
	{
		cycle = ol;
		int temp = A[ol]; //element to be replaced
		do
		{
			nl = (ol * m) % (size-1);
			swap(&A[nl], &temp);
			visited[ol] = 1;
			ol = nl;
			
		}while(ol != cycle);
		
		for(ol = 1; ol < size-1 && visited[ol]; ol++);
	}
}

void printMatrix(int A[], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", *(A + i*n + j));
		}
		printf("\n");
	}
}

int main() 
{
	int i, j, m, n;
	int A[50];
	scanf("%d%d", &m, &n);
	
	for(i = 0; i < m*n; i++) 
	{
		scanf("%d", &A[i]);
	}

	printMatrix(A, m, n);
	transpose(A, m, n);
	printMatrix(A, n, m);
	
	return 0;
}

