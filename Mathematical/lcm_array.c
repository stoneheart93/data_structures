#include<stdio.h>
 
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}
 
int lcmArray(int a[], int n)
{
	int result = a[0];
	int i;
	
	for(i= 1; i < n; i++)
		result = ( (result * a[i]) / gcd(result, a[i]));
		
	return result;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", lcmArray(a, n));
	return 0;
}
