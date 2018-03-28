#include<stdio.h>

int array_even(int a[], int n)
{
	int i, count = 0;
	for(i = 0; i <n; i++)
	{
		if(a[i] % 2 != 0)
			count++;
	}
	if(count % 2 == 0)
		return 0;
	else
		return 1;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", array_even(a, n));
	return 0;
}

