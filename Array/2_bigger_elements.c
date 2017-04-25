#include<stdio.h>

void findElements(int a[], int n)
{
    int first = 0, second = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] > first)
        {
            second = first;
            first = a[i];
        }
 		else if(a[i] > second)
        	second = a[i];
    }
 
    for(i = 0; i < n; i++)
    {
    	if(a[i] < second)
            printf("%d ",a[i]);	
	}
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	findElements(a, n);
	return 0;
}
 
