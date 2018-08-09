#include<stdio.h>

struct pair 
{
	int min;
	int max;
};  
 
struct pair getMinMax(int a[], int low, int high)
{
	struct pair minmax, mml, mmr;       
	int mid;
	   
	if(low == high)
	{
    	minmax.max = a[low];
    	minmax.min = a[low];     
    	return minmax;
  	}    
   
	if(high == low + 1)
	{  
    	if(a[low] > a[high])  
    	{
        	minmax.max = a[low];
        	minmax.min = a[high];
     	}  
     	else
     	{
        	minmax.max = a[high];
        	minmax.min = a[low];
     	}	  
     	return minmax;
  	}
   
  	mid = (low + high)/2;  
  	mml = getMinMax(a, low, mid);
  	mmr = getMinMax(a, mid+1, high);  
   
  	if(mml.min < mmr.min)
    	minmax.min = mml.min;
  	else
    	minmax.min = mmr.min;     
 
  	if(mml.max > mmr.max)
    	minmax.max = mml.max;
  	else
		minmax.max = mmr.max;     
  	return minmax;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	struct pair minmax = getMinMax(a, 0, n - 1);
  	printf("\nMinimum element is %d", minmax.min);
  	printf("\nMaximum element is %d", minmax.max);
  	return 0;
}
