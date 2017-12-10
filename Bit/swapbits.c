#include <stdio.h>
 
int swapPositionBits(int x, int p1, int p2, int n)
{
	int set1 = (x >> p1) & ((1U << n) - 1);
	int set2 = (x >> p2) & ((1U << n) - 1);
	
	int xor_bits = set1 ^ set2;
	xor_bits = (xor_bits << p1) | (xor_bits << p2);
	
	return (x ^ xor_bits);
}

int main()
{
    int x = 28; 
	int p1 = 0;
	int p2 = 3;
	int n = 2;
	printf("%d", swapPositionBits(x, p1, p2, n));
	return 0;
}
