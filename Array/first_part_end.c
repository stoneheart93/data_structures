#include <stdio.h>
 
void rev(int a[], int start, int end)
{
	int temp;
   	if (start >= end)
    	return;
   	temp = a[start];   
   	a[start] = a[end];
   	a[end] = temp;
   	rev(a, start + 1, end - 1);   
} 

void firstPartEnd(int a[], int n, int k)
{
	rev(a, 0, k - 1);
	rev(a, k, n - 1);
	rev(a, 0, n - 1);			
}    
 
int main() 
{
    int n, i, k;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	firstPartEnd(a, n, k);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

