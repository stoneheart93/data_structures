#include<stdio.h>

int pairsSumLessX(int a[], int n, int x)
{
    int l = 0, r = n-1;
    int result = 0;
    while(l < r)
    {
        if (a[l] + a[r] < x)
        {
            result += (r - l);
            l++;
        }
        else
        	r--;
    }
    return result;
}

int main() 
{
    int n, i, x;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &x);
	printf("%d ", pairsSumLessX(a, n, x));
	return 0;
}

