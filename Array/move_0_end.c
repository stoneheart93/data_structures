#include<stdio.h>

void pushZerosToEnd(int a[], int n)
{
    int i, j = 0;
	for(i = 0; i < n; i++)
    {
    	
		if(a[i] != 0)
            a[j++] = a[i];
    }
	
	while(j < n)
        a[j++] = 0;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	pushZerosToEnd(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
} 

