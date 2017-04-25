#include <stdio.h>

int parity(int n)
{
    int parity=0;
    while(n)
    {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("Parity of no %d = %s", n, (parity(n)? "odd": "even"));
    return 0;
}
