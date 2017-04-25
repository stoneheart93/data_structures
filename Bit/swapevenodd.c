#include <stdio.h>

int swapBits(int n)
{
    int even_bits = n & 0xAAAAAAAA; 
    int odd_bits = n & 0x55555555; 
    even_bits >>= 1;  
    odd_bits <<= 1;   
    return (even_bits | odd_bits); 
}

int main()
{
    int x = 23; // 00010111
    // Output is 43 (00101011)
    printf("%d", swapBits(x));
	return 0;
}
