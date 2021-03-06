#include<stdio.h>
#include<limits.h>
 
int maxDiff(int a[], int n)
{
	int max_diff = INT_MIN;
  	int min_element = INT_MAX;
  	int i;
  	for(i = 0; i < n; i++)
  	{	       
    	if(a[i] < min_element)
        	min_element = a[i];                     
		if(a[i] - min_element > max_diff)                               
    		max_diff = a[i] - min_element;	
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
