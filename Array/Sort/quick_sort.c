#include<stdio.h>
 
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];    
    int i = (low - 1);  
	int j;
    for(j = low; j <= high- 1; j++)
    {
        if(a[j] <= pivot)
        {
            i++;    
            swap(&a[i], &a[j]);
        }
    }
    i++;
    swap(&a[i], &a[high]);
    return i;
}

void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);	
		quick_sort(a, low, p - 1);
        quick_sort(a, p + 1, high);
    }
}
  
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quick_sort(a, 0, n - 1);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
