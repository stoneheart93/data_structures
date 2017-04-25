#include<stdio.h>

int isPowerOfTwo(int n)
{
    return (n && (! (n & (n - 1))) );
}
int position(int n)
{
    int count=0;
    if(!isPowerOfTwo(n))
		return -1;
	while(n) 
    {
        n >>= 1;
        count+=1;
    }
    return count;
}    
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", position(n));
    return 0;
}
