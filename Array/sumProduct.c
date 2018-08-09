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

void leftRotate(int a[], int n, int k)
{
	int mod = k % n;
	rev(a, 0, mod - 1);
	rev(a, mod, n - 1);
	rev(a, 0, n - 1);	
}    
 
void rightRotate(int a[], int n, int k)
{
	int mod = k % n;
	rev(a, 0, n - 1);
	rev(a, 0, mod - 1);
	rev(a, mod, n - 1);	
}

int main() 
{
    int n, i;
	int a[20], a_temp[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a_temp[i] = a[i];
	}
	
	printf("\nLeft Rotation: ");
	leftRotate(a_temp, n, 15);
	for(i = 0; i < n; i++)
		printf("%d ", a_temp[i]);
	
	printf("\nRight Rotation: ");
	rightRotate(a, n, 2);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
}

/*
ip
7
1 2 3 4 5 6 7
op
Left Rotation: 3 4 5 6 7 1 2
Right Rotation: 6 7 1 2 3 4 5
*/
