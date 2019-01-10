#include<stdio.h>
#include<limits.h>
 
int max(int a, int b)
{
	return (a > b) ? a : b;	
}

int transaction(int a[], int n)
{
	int profit[n];
	
	int i;
    for(i = 0; i < n; i++) 
        profit[i] = 0; 
  
  	int max_price = a[n-1]; 
    for(i = n - 2; i >= 0; i--) 
    { 
        if(a[i] > max_price) 
        	max_price = a[i]; 

        profit[i] = max(profit[i+1], max_price - a[i]); 
    } 
  
    int min_price = a[0]; 
    for(i = 1; i < n; i++) 
    { 
        if(a[i] < min_price) 
        	min_price = a[i]; 
  
        profit[i] = max(profit[i-1], profit[i] + a[i] - min_price); 
    }
	 
    return profit[n-1]; 
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

