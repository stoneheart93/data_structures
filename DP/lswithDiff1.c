#include<stdio.h>

int longestSubseqWithDiffOne(int a[], int n)
{
    int lis[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        lis[i] = 1;
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if((a[i] == a[j] + 1 || a[i] == a[j] - 1) && lis[i] < lis[j] + 1)
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
    printf("%d", longestSubseqWithDiffOne(a,n));
    return 0;
}

