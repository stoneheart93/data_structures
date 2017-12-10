#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;
    if(gap < 1)
        return 1;
    return gap;
}
 
void comb_sort(int a[], int n)
{
    int gap = n;
	int swapped = 1, i;
    while(gap != 1 || swapped == 1)
    {
        gap = getNextGap(gap);
        swapped = 0;
        for(i = 0; i < n - gap; i++)
        {
            if(a[i] > a[i+gap])
            {
                swap(&a[i], &a[i+gap]);
                swapped = 1;
            }
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
	comb_sort(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}


