#include<stdio.h>

int segregatePosNeg(int a[], int n)
{
	int i, j = 0;
	int temp[n];
	for(i = 0; i < n; i++)
	{
		if(a[i] >= 0)
			temp[j++] = a[i];
	}
	
	if(j == 0 || j == n)
		return;
	
	for(i = 0; i < n; i++)
	{
		if(a[i] < 0)
			temp[j++] = a[i];
	}
	
	memcpy(a, temp, sizeof(temp));
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	segregatePosNeg(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
} 

/*
ip
8
1 -1 -3 -2 7 5 11 6
op
1 7 5 11 6 -1 -3 -2
*/
