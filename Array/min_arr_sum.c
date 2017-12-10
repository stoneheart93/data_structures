#include<stdio.h>

int gcd(int a, int b)
{
    if(a == 0)
		return b;
    return gcd (b % a, a);
}
 
int minSum(int a[], int n)
{
	int i;
    int ans = a[0];
    for(i = 0; i < n; i++)    
        ans = gcd(ans, a[i]);

    return n * ans;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", minSum(a, n));
	return 0;
}

/*
ip 
3
2 2 6
op 
6
*/

