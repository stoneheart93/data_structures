#include<stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
 
void tripletSum(int a[], int n, int sum)
{
    int l, r, i, found = 0;
    qsort(a, n, sizeof(int), compare);
    for(i = 0; i < n - 2; i++)
    {
    	l = i + 1; 
        r = n - 1; 
		while(l < r)
        {
            if(a[i] + a[l] + a[r] == sum)
            {
                printf("Triplet is %d, %d, %d", a[i], a[l], a[r]);
                found = 1;
			}
            else if(a[i] + a[l] + a[r] < sum)
                l++;
            else 
                r--;
        }
    }
    if(found == 0)
    	printf("No triplet");
}

int main()
{
	int n, i, sum;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &sum);
	tripletSum(a, n, sum);
	return 0;
}

/*
ip
6
1 4 45 6 10 8
22
op
Triplet is 4, 8, 10
*/
