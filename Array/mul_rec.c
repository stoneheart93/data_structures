#include<stdio.h>

int multiply(int a[], int n)
{
    if(n == 0)
        return(a[n]);
    else
        return (a[n] * multiply(a,n-1));
}
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", multiply(a, n));
    return 0;    

}
