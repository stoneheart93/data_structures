#include<iostream>
#include<algorithm>
using namespace std;

struct CityPairs 
{ 
    int north, south; 
}; 
  
bool compare(struct CityPairs a, struct CityPairs b) 
{ 
    if (a.south == b.south) 
        return a.north < b.north; 
    return a.south < b.south; 
}

int maxBridges(struct CityPairs a[], int n) 
{ 
	int i, j, max = 0;
    int lis[n]; 
    for(i = 0; i < n; i++) 
    	lis[i] = 1; 
          
    sort(a, a + n, compare); 
      
    for(i = 1; i < n; i++)
	{
	    for (j = 0; j < i; j++) 
        {
        	if(a[i].north >= a[j].north && lis[i] < 1 + lis[j]) 
                lis[i] = 1 + lis[j]; 
        }
    }
          
    for(i = 1; i < n; i++) 
    {
    	if(max < lis[i]) 
        	max = lis[i]; 
  	}
    
	return max;         
} 

int main() 
{ 
    struct CityPairs a[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}}; 
    int n = 4; 
    printf("Maximum number of bridges: %d", maxBridges(a, n));     
    return 0; 
}  
