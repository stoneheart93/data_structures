#include<stdio.h>

int min(int a, int b)
{
	return (a < b) ? a : b;
}
int minTime(int a[], int n)
{
	int incl = a[0];
	int excl = 0;
	
	int incl_new, excl_new;
	
	int i;
	for(i = 1; i < n; i++)
	{
		incl_new = a[i] + min(incl, excl); 
		excl_new = incl; // previous element must be included as two consecutive jobs cant be skipped
		
		incl = incl_new;
		excl = excl_new;
	}
	return min(incl, excl);
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", minTime(a,n));
    return 0;
}
