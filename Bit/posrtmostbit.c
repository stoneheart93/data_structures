#include<stdio.h>
#include<math.h>

int rightMostSetBitPos(int n)
{
   return log2(n & - n) + 1;
}
 
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", rightMostSetBitPos(n));
    return 0;
}
