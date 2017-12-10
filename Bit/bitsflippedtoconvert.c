#include<stdio.h>

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

int flipBits(int a, int b)
{
	int a_xor_b = a ^ b;
	return (countSetBits(a_xor_b));
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", flipBits(a, b));
    return 0;
}
