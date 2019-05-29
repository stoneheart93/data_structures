#include<stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}
int maxSum_notadj(int a[], int n)
{
    int C[n];
    int i;
    
    C[0] = a[0];
    C[1] = max(a[0], a[1]);
    
	for(i = 2; i < n; i++)
        C[i] = max(a[i] + C[i - 2], //include
			   C[i - 1]); //exclude
    return C[n - 1];
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", maxSum_notadj(a,n));
    return 0;
}
