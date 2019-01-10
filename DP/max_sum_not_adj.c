#include<stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}
int maxSum_notadj(int a[], int n)
{
	int incl = a[0];
	int excl = 0;
	
	int incl_new, excl_new;
	
	int i;
	for(i = 1; i < n; i++)
	{
		incl_new = a[i] + excl; // include the element, and exclude the previous element since not adjacent
		excl_new = max(incl, excl);
		
		incl = incl_new;
		excl = excl_new;
	}
	return max(incl, excl);
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", maxSum_notadj(a,n));
    return 0;
}
