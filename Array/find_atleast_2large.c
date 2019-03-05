#include<stdio.h>
#include<limits.h>

void findAtLeast2large(int a[], int n)
{
	int i;
	int first_max = INT_MIN, sec_max = INT_MIN;
	for(i = 0; i < n; i++)
	{
		if(a[i] > first_max)
		{
			sec_max = first_max;
			first_max = a[i];
		}
		else if(a[i] > sec_max)
			sec_max = a[i];
	}
	for(i = 0; i < n; i++)
    {
		if(a[i] < sec_max)
        	printf("%d ", a[i]);
    }
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	findAtLeast2large(a, n);
	return 0;
}

