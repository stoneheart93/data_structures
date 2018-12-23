#include<stdio.h>

int isPowerOf2(int n)
{
	return n && !(n & (n - 1));
}
int nextPowerOf2(int n)
{
    if(isPowerOf2(n))
    	return n;
    
    int p = 1;
    while(p < n)
    	p <<= 1;
    return p;
}  

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", nextPowerOf2(n));
    return 0;
}
 
