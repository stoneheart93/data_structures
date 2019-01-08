#include<stdio.h>

int Mpis(int a[], int n)
{
    int mpis[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        mpis[i] = a[i];
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if(a[i] > a[j] && mpis[i] < mpis[j] * a[i])
                mpis[i] = mpis[j] * a[i];
        }
    }
    for(i = 0; i < n; i++)
    {
    	if(mpis[i] > max)
        	max = mpis[i];
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
    printf("%d", Mpis(a,n));
    return 0;
}

