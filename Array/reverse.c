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
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	rev(a, 0, n - 1);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

/*
ip
5
1 2 3 4 5
op
5 4 3 2 1
*/
