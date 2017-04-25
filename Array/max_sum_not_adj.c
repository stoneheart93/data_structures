#include<stdio.h>
 
int findMaxSum(int a[], int n)
{
	int incl = a[0];
  	int excl = 0;
  	int excl_new;
  	int i;
 
  	for (i = 1; i < n; i++)
  	{
    	excl_new = (incl > excl)? incl: excl;
     	incl = excl + a[i];
     	excl = excl_new;
  	}
 
	return ((incl > excl)? incl : excl);
}
 
int main()
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", findMaxSum(a, n));
    return 0;    
}    

/*
ip
6
5 5 10 100 10 5
op
110
*/
