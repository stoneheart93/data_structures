#include<stdio.h>

void modifyMatrix(int M[10][10], int m, int n)
{
	int row[m];
    int col[n];
    int i, j;
 
    memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
		
	for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(M[i][j] == 1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
 
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                M[i][j] = 1;
            }
        }
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
	modifyMatrix(M, m, n);
	for(i = 0; i < m; i++) 
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
3 4
1 0 0 1
0 0 1 0
0 0 0 0
op
1 1 1 1
1 1 1 1
1 0 1 1*/
