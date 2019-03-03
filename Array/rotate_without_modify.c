#include <stdio.h>
 
void left_rotate(int a[], int n, int k)
{
	int i;
	for(i = k; i < n + k; i++)
		printf("%d ", a[i % n]);
	printf("\n"); 
}    
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int k = 2;
	left_rotate(a, n, k);
	
	k = 3;
	left_rotate(a, n, k);

	return 0;
}

