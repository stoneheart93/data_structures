#include<stdio.h>
#define INIT_MAX 9999999

void print2smallest(int a[], int n)
{
	int i;
	int first_min = INIT_MAX, sec_min = INIT_MAX;
	for(i = 0; i < n; i++)
	{
		if(a[i] < first_min)
		{
			sec_min = first_min;
			first_min = a[i];
		}
		if(a[i] < sec_min)
			sec_min = a[i];
	}
	printf("%d %d", first_min, sec_min);
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	print2smallest(a, n);
	return 0;
}

/*
ip
6
12 13 1 10 34 1
op
1 10
*/
