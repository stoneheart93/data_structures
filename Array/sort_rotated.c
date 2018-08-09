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

void sort_rotated(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(a[i] > a[i + 1])
		{
			rev(a, 0, i);
			rev(a, i + 1, n - 1);
			rev(a, 0, n - 1);			
		}
	}
}    
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	sort_rotated(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

