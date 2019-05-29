#include <stdio.h>

/*
The time complexity is O(k) where k are the number of set bits

int countSetBits(int n)
{
    int count = 0;
    while(n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int parity(int n)
{
    return (countSetBits(n) % 2)== 0 ? 0 : 1; 
}
*/

// O(log n)
int parity(int n)
{
//	n ^= n >> 32; // for 64 bit/8 byte integer
	n ^= n >> 16;
	n ^= n >> 8;
	n ^= n >> 4;
	n ^= n >> 2;
	n ^= n >> 1;
	return n;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("Parity of no %d = %s", n, (parity(n)? "odd": "even"));
    return 0;
}
