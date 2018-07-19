#include<stdio.h>
 
void swap(int* a, int* b)
{
	int temp = *a;
    *a = *b;
    *b = temp;
}
 
void randomize(int a[], int n)
{
	int i;
    srand(time(NULL));
 
    for(i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&a[i], &a[j]);
    }
}
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	randomize(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
