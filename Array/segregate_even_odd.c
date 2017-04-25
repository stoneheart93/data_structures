#include<stdio.h>
 
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void segregateEvenOdd(int a[], int n)
{
	int left = 0, right = n - 1;
 
    while (left < right)
    {
        while (a[left] % 2 == 0 && left < right)
            left++;
 
 	    while (a[right] % 2 != 0 && left < right)
            right--;
 
        if (left < right)
        {
            swap(&a[left], &a[right]);
            left++;
            right--;
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
	segregateEvenOdd(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

