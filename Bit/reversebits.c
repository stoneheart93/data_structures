#include <stdio.h>
 
unsigned int swapPositionBits(unsigned int n, int p1, int p2)
{
	unsigned int p1_bit = 1 << p1;
	unsigned int p2_bit = 1 << p2;
	
	//For same bits, there would be no change
	if( (n & p1_bit) ^ (n & p2_bit) )
	{
		n ^= p1_bit;
		n ^= p2_bit;	
	}
	return n;
}

unsigned int reverseBits(unsigned int n)
{
	int i;
	int MAX_BITS = sizeof(n) * 8;
	
	for(i = 0; i < MAX_BITS/2; i++)
		n = swapPositionBits(n, i, MAX_BITS - i - 1);
	
	return n;
}
 
int main()
{
    unsigned int num;
	scanf("%u", &num); 
    printf("%u", reverseBits(num));
    return 0;
}

/*
ip 
2 
op
1073741824
*/
