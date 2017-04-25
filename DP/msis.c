#include<stdio.h>

int Msis(int a[], int n)
{
    int msis[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        msis[i] = a[i];
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if(a[i] > a[j] && msis[i] < msis[j] + a[i])
                msis[i] = msis[j] + a[i];
        }
    }
    for(i = 0; i < n; i++)
    {
    	if(msis[i] > max)
        	max = msis[i];
    }
    return max;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", Msis(a,n));
    return 0;
}

/*
ip:
7
1 101 2 3 100 4 5
op:
106
*/ 
