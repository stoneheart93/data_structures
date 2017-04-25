#include<stdio.h>

int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int pairsDiffK(int a[], int n, int k)
{
    int count = 0;
    qsort(a, n, sizeof(int), compare);  
    int l = 0, r = 0;
    
	while(r < n)
    {
        if(a[r] - a[l] == k)
        {
            count++;
            l++;
            r++;
        }
        else if(a[r] - a[l] > k)
            l++;
        else 
		    r++;
    }   
    return count;
}

int main() 
{
    int n, i, k;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	printf("%d ", pairsDiffK(a, n, k));
	return 0;
}

