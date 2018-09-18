#include<stdio.h>

struct pair
{
	int a, b;
};

int maxChainLen(struct pair a[], int n)
{
    int lis[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        lis[i] = 1;
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if(a[i].a > a[j].b && lis[i] < lis[j] + 1)
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
	int n = 4;
	struct pair a[] = { {5,24}, {15,25},
						{27,40}, {50,60}};
	printf("%d", maxChainLen(a,n));
    return 0;
}

