#include<stdio.h>

int pairs_sum(int a[], int n, int sum)
{
    int l, r, i;
    
    for(i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i+1])
        	break;
    }
    
    l = (i + 1) % n;
    r = i; 
    while(l != r)
    {
		if(a[l] + a[r] == sum)
		{
			printf("%d, %d\n", a[l], a[r]);
			return;
        }
		else if(a[l] + a[r] < sum)
            l = (l + 1) % n;
        else // A[i] + A[j] > sum
            r = (n + r - 1) % n;
    }    
    printf("No candidates");
}
 
int main()
{
	int n, i, sum;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &sum);
	pairs_sum(a, n, sum);
	return 0;
}
