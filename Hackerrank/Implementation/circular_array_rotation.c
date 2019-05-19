#include<stdio.h>

void rev(int a[], int start, int end)
{
    if(start >= end)
    	return;
    	
   	int temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    rev(a, start + 1, end - 1);
}

void rightRotate(int a[], int n, int k)
{
	int mod = k % n;
	rev(a, 0, n - 1);
    rev(a, 0, mod - 1);
    rev(a, mod, n - 1);
}

int main()
{
	int n, k, q, i, index; 
    scanf("%d%d%d", &n, &k, &q);
    int a[n];
    for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    
	rightRotate(a, n, k);
	
    for(i = 0; i < q; i++)
	{
    	scanf("%d", &index);
    	printf("%d\n", a[index]);
    }
    return 0;
}


