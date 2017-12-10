#include<stdio.h>

int gcd(int a, int b)
{
    if(a == 0)
		return b;
    return gcd (b % a, a);
}
 
int findNumber(int a[], int n)
{
	int i;
    int ans = a[0];
    for(i = 0; i < n; i++)    
        ans = gcd(ans, a[i]);
     
    for(i = 0; i < n; i++)
	{
        if(a[i] == ans)         
        	return ans;        
	}
    return -1;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", findNumber(a, n));
	return 0;
}

/*
ip 
3
2 2 4
op 
2
*/

