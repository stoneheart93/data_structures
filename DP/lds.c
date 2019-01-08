#include<stdio.h>

int Lds(int a[], int n)
{
    int lds[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        lds[i] = 1;
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if(a[i] < a[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
    }
    for(i = 0; i < n; i++)
    {
    	if(lds[i] > max)
        	max = lds[i];
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
    printf("%d", Lds(a,n));
    return 0;
}

