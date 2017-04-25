#include<stdio.h>
 
int maxDiff(int a[], int n)
{
	int max_diff = a[1] - a[0];
  	int min_element = a[0];
  	int i;
  	for(i = 1; i < n; i++)
  	{	       
    	if (a[i] - min_element > max_diff)                               
    		max_diff = a[i] - min_element;
    	if (a[i] < min_element)
        	min_element = a[i];                     
  	}
  	return max_diff;
}    

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", maxDiff(a, n));
	return 0;
}

/*
ip
5
1 2 6 8 100
op
99
*/
