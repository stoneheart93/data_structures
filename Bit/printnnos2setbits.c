#include<stdio.h>

void printTwoSetBitNums(int n)
{
    int x = 1;
    while (n > 0)
    {
        int y = 0;
        while (y < x)
        {
            printf("%d\n", (1 << x) + (1 << y) );
            n--;
            if (n == 0)
                return;
            y++;
        }
        x++;
    }
}
 
int main()
{
	int n;
	scanf("%d", &n);
    printTwoSetBitNums(n);
    return 0;
}
