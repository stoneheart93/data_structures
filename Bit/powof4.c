#include<stdio.h>

int isPowerOfTwo(int n)
{
    return (n && (! (n & (n - 1))) );
}
int isPowerOfFour(int n)
{
    int count=0;
    if(isPowerOfTwo(n)) 
    {
        while(n > 1)
        {
            n >>= 1;
            count+=1;
        }      
        return (count % 2 == 0) ? 1 : 0;
    }
    return 0;
}    
int main()
{
    int n;
    scanf("%d", &n);
    if(isPowerOfFour(n))
       printf("%d is a power of 4", n);
    else
       printf("%d is not a power of 4", n);
    return 0;
}
