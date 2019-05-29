#include<stdio.h>
#include<limits.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int maxIndexDiff(int a[], int n)
{
	int L[n], R[n];
	int i, j;
	int maxDiff = INT_MIN;
	
	L[0] = a[0];
	for(i = 1; i < n; i++)
		L[i] = min(L[i - 1], a[i]);
		
	R[n - 1] = a[n - 1];
	for(i = n - 2; i >= 0; i--)
		R[i] = max(R[i + 1], a[i]);
		
	i = 0, j = 0;
	while(i < n && j < n)
	{
		if(L[i] < R[j])
		{
			maxDiff = max(maxDiff, j - i);
			j++;
		}
		else
			i++;
	}
	
	return maxDiff;
}
		
int main()
{
	int a[100];
    int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", maxIndexDiff(a, n));
	return 0;
}
