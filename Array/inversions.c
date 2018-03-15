#include<stdio.h>
 
int merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int inv_count = 0;
 
    int L[n1], R[n2];
 
    for(i = 0; i < n1; i++)
    	L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
	while(i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
            inv_count = inv_count + (n1 - i);
        }
        k++;
    }
 
    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
	while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    return inv_count;
}
 
int merge_sort(int a[], int l, int r)
{
	int inv_count = 0;
    if(l < r)
    {
		int m = l + (r - l)/2;
		inv_count += merge_sort(a, l, m);
        inv_count += merge_sort(a, m + 1, r);
        inv_count += merge(a, l, m, r);
    }
    return inv_count;
}
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", merge_sort(a, 0, n - 1));
	for(i = 0; i < n; i++)
		printf("%d", a[i]);
	return 0;
}
