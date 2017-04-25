#include<stdio.h>

int nextHigherSameBits(int x)
{
	int rightmost = x & -x;
	int ripple = x + rightmost;
	int left_adjustment = ripple;
	
	int ones = x ^ ripple;
	ones = ones >> 2;
	int right_adjustment = ones/rightmost;
 
 	return (left_adjustment | right_adjustment);
}
 
int main()
{
    int x;
    scanf("%d", &x);
    printf("Next higher number with same number of set bits is %d", nextHigherSameBits(x));
	return 0;
}
