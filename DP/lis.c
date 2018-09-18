#include<stdio.h>

int Lis(int a[], int n)
{
    int lis[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        lis[i] = 1;
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if(a[i] > a[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    for(i = 0; i < n; i++)
    {
    	if(lis[i] > max)
        	max = lis[i];
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
    printf("%d", Lis(a,n));
    return 0;
}

/*
ip:
8
10 22 9 33 21 50 41 60
op:
5
*/ 
