#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int minXOR(int a[], int n) 
{ 
    sort(a, a + n); 
  
    int minXor = INT_MAX; 
    int val = 0; 
  
    for(int i = 0; i < n - 1; i++) 
        minXor = min(minXor, a[i] ^ a[i+1]); 
  
    return minXor; 
}

int main()
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", minXOR(a, n));
    return 0;    
}
