#include<stdio.h>

int Msds(int a[], int n)
{
    int msds[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        msds[i] = a[i];
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if(a[i] < a[j] && msds[i] < msds[j] + a[i])
                msds[i] = msds[j] + a[i];
        }
    }
    for(i = 0; i < n; i++)
    {
    	if(msds[i] > max)
        	max = msds[i];
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
    printf("%d", Msds(a,n));
    return 0;
}

