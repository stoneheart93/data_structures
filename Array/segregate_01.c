#include<stdio.h>
 
void segregate01(int a[], int n)
{
	int left = 0, right = n - 1;
 
    while (left < right)
    {
        while (a[left] == 0 && left < right)
            left++;
 
 	    while (a[right] == 1 && left < right)
            right--;
 
        if (left < right)
        {
            a[left] = 0;
            a[right] = 1;
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
	segregate01(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}

