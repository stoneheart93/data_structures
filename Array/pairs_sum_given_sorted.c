#include<stdio.h>

void pairs_sum(int a[], int n, int sum)
{
    int l = 0, r = n - 1;
    
	while(l < r)
    {
		if(a[l] + a[r] == sum)
		{
			printf("%d, %d\n", a[l], a[r]);
			l++;
			r--;
        }
		else if(a[l] + a[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
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
