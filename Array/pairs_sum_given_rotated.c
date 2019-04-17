#include<stdio.h>

void pairs_sum(int a[], int n, int sum)
{
    int i;
    
    for(i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i+1])
        	break;
    }
    
    int l = (i + 1) % n;
    int r = i; 
    while(l != r)
    {
		if(a[l] + a[r] == sum)
		{
			printf("%d, %d\n", a[l], a[r]);
			
			if(l == (r - 1 + n) % n)
            	return;
             
            l = (l + 1) % n;
            r = (r - 1 + n) % n;
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
