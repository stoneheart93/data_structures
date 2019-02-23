#include <stdio.h>
 
int swapPositionBits(int n, int p1, int p2)
{
	int p1_bit = 1 << p1;
	int p2_bit = 1 << p2;
	
	//For same bits, there would be no change
	if( (n & p1_bit) ^ (n & p2_bit) )
	{
		n ^= p1_bit;
		n ^= p2_bit;	
	}
	return n;
}

int main()
{
    int n, p1, p2;
	scanf("%d %d %d", &n, &p1, &p2);
	printf("%d", swapPositionBits(n, p1, p2));
	return 0;
}
