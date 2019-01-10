#include<iostream>
#include<algorithm>
using namespace std;

struct job 
{ 
    int start, end, profit; 
}; 
  
bool myCompare(struct job a, struct job b) 
{ 
    return (a.end < b.end); 
} 
  
int binSearch(struct job a[], int index) 
{ 
    int low = 0, high = index - 1; 
  
    while(low <= high) 
    { 
        int mid = low + (high - low) / 2; 
        if(a[mid].end <= a[index].start) 
        { 
            if(a[mid + 1].end <= a[index].start) 
                low = mid + 1; 
            else
                return mid; 
        } 
        else
            high = mid - 1; 
    } 
    return -1; 
} 
  
int weightedJS(struct job a[], int n) 
{ 
    sort(a, a+n, myCompare); 
  
    int DP[n]; 
    DP[0] = a[0].profit; 

	int i; 
    for(i = 1; i < n; i++) 
    { 
        int incl = a[i].profit; 
        
		int l = binSearch(a, i); 
        if (l != -1) 
            incl += DP[l]; 
  
        DP[i] = max(incl, DP[i-1]); 
    } 
  
    return DP[n-1]; 
} 
  
int main() 
{ 
    struct job a[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
    int n = 4; 
    printf("Optimal profit is %d", weightedJS(a, n)); 
    return 0; 
} 
