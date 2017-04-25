#include<stdio.h>
 
int countElements(int a[], int n)
{
    int result = 1;
    int max_ele = a[0];
    int i;
	for(i = 1; i < n; i++)
    {
        if (a[i] > max_ele)
        {
            max_ele = a[i];
            result++;
        }
    } 
    return result;
}
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", countElements(a, n));
	return 0;
}
