#include<stdio.h>

int singleThrice(int a[], int n) 
{
    int MAX_BITS = 4 * sizeof(int);
    int i, j;
    int result = 0;
    for(i = 0; i < n; i++)
    {
        int x = 1 << i;
        int count = 0;
        for(j = 0; j < n; j++)
            if(x & a[j])
                count++;
        if(count % 3 != 0)
            result |= x;
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
	printf("%d", singleThrice(a, n));
    return 0;    
}
