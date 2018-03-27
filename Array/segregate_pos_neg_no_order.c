#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void segregatePosNeg(int a[], int n)
{
    int i = -1, j;
    for(j = 0; j < n; j++)
    {
        if(a[j] >= 0)
        {
            i++;
        	swap(&a[i], &a[j]);
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
	segregatePosNeg(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

