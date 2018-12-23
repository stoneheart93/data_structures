#include<stdio.h>
#include<math.h>

int isPowerOfTwo(int n)
{
    return (n && (! (n & (n - 1))) );
}

int position(int n)
{
    if(!isPowerOfTwo(n))
		return -1;
	return log2(n) + 1;
}    
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", position(n));
    return 0;
}
