#include<stdio.h>
#define INT_BITS 32

int leftRotate(int n, int d)
{
	return (n << d) | (n >> (INT_BITS - d));
}
int rightRotate(int n, int d)
{
   return (n >> d) | (n << (INT_BITS - d));
}
int main()
{
    int n,d;
    scanf("%d",&n);
    scanf("%d",&d);
    printf("Left Rotation of %d by %d is %d\n", n, d, leftRotate(n,d));
    printf("Right Rotation of %d by %d is %d\n",n, d, rightRotate(n,d));
    return 0;
} 
