#include<stdio.h>

void productArray(int a[], int n)
{
	int i, temp = 1;
 	int prod[n];
 	
 	for(i = 0; i < n; i++)
  	{	
    	prod[i] = temp;
    	temp *= a[i];
  	}
 
  	temp = 1;
 
 	for(i = n - 1; i >= 0; i--)
  	{
    	prod[i] *= temp;
    	temp *= a[i];
  	}
 
  	for(i = 0; i < n; i++)
    	printf("%d ", prod[i]);
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	productArray(a, n);
	return 0;
}

/*
ip
5
10 3 5 6 2
op
180 600 360 300 900
*/
