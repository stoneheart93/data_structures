#include <stdio.h>

int swapNibbles(int n)
{
    int first_nibble = n & 0xF0; 
    int second_nibble = n & 0x0F; 
    first_nibble >>= 4;  
    second_nibble <<= 4;   
    return (first_nibble | second_nibble); 
}

int main()
{
    int x = 100; // 01100100
    // output 01000110 
    printf("%d", swapNibbles(x));
	return 0;
}
