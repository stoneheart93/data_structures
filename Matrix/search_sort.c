#include<stdio.h>

int search(int M[20][20], int m, int n, int x) 
{
    int low = 0, high = m*n - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int mid_i = mid / n;
        int mid_j = mid % n;
        if(x == M[mid_i][mid_j])
        {
        	printf("%d %d", mid_i, mid_j);
        	return 1;
		}
        else if(x < M[mid_i][mid_j])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main() 
{
	int i, j, m, n, x;
	int M[20][20];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	scanf("%d", &x);
	if(!search(M, m, n, x))
		printf("Not found");
	else
		printf("Found");
	return 0;
}
