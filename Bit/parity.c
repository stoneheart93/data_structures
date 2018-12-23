#include <stdio.h>

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

int main()
{
    int n;
    scanf("%d", &n);
    printf("Parity of no %d = %s", n, (parity(n)? "odd": "even"));
    return 0;
}
