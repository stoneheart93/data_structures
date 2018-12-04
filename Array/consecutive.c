#include<stdio.h>
#include<limits.h>

int isConsecutive(int a[], int n)
{
	int sum = 0;
	int first_term = INT_MAX;
	
	int i;
	for(i = 0; i < n; i++)
	{
		if(a[i] < first_term)
			first_term = a[i];
		sum += a[i];
	}
	// AP = n/2 * [2a + (n-1)d]
	int ap_sum = (n * (2 * first_term + (n-1)))/2;
	return (sum == ap_sum);
}

int main()
{
	int a[100];
    int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if(isConsecutive(a, n))
		printf("Array elements are consecutive");
	else
		printf("They are not consecutive");
    return 0;
}
