#include<stdio.h>
#include<limits.h>
 
int transaction(int a[], int n)
{
	int max_profit = INT_MIN;
  	int min_element = INT_MAX;
  	int i;
  	for(i = 0; i < n; i++)
  	{	       
    	if(a[i] < min_element)
        	min_element = a[i];                     
		if(a[i] - min_element > max_profit)                               
    		max_profit = a[i] - min_element;	
  	}
  	return max_profit;
}    

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", transaction(a, n));
	return 0;
}

