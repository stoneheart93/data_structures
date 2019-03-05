#include<stdio.h>
#include<limits.h>
 
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

int random_partition(int a[], int low, int high)
{
    int n = high - low + 1;
    int pivot = rand() % n;
    swap(&a[low + pivot], &a[high]);
    return partition(a, low, high);
}

int quick_select(int a[], int low, int high, int k)
{
    if(low == high && k == low)
    	return a[low];
    
	int p = random_partition(a, low, high);
	if(p == k - 1)
		return a[p];
	else if(p > k - 1)	
		return quick_select(a, low, p - 1, k);
	else
       	return quick_select(a, p + 1, high, k);
}
  
int main() 
{
    int n, i, k;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	printf("%d", quick_select(a, 0, n - 1, k));
	return 0;
}
