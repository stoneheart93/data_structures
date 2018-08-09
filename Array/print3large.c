#include<stdio.h>
#include<limits.h>

void print3largest(int a[], int n)
{
	int i;
	int first_max = INT_MIN, sec_max = INT_MIN, third_max = INT_MIN;
	for(i = 0; i < n; i++)
	{
		if(a[i] > first_max)
		{
			third_max = sec_max;
			sec_max = first_max;
			first_max = a[i];
		}
		else if(a[i] > sec_max)
		{
			third_max = sec_max;
			sec_max = a[i];
		}
		else if(a[i] > third_max)
			third_max = a[i];
	}
	printf("%d %d %d", first_max, sec_max, third_max);
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	print3largest(a, n);
	return 0;
}

