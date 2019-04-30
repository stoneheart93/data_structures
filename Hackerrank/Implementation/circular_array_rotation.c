#include<stdio.h>

void rev(int a[], int start, int end)
{
    int temp;
    while(start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void rightRotate(int a[], int d, int n)
{
	rev(a, 0, n-1);
    rev(a, 0, d-1);
    rev(a, d, n-1);
}

int main()
{
	int n, d, q, i, index; 
    scanf("%d%d%d", &n, &d, &q);
    d = d % n;
    int a[n];
    for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
    }
    rightRotate(a, d, n);
    for(i = 0; i < q; i++)
	{
    	scanf("%d", &index);
    	printf("%d\n", a[index]);
    }
    return 0;
}


