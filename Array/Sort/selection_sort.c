#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int a[], int n)
{
	int i, j, min;
 	
	for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
        	if(a[j] < a[min])
            	min = j;
 		}
        swap(&a[min], &a[i]);
    }
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	selection_sort(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

