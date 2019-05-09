#include<stdio.h>
#include<math.h>

int reverse(int n)
{
    int num = 0;
    while(n)
    {
        int rem = n % 10;
        n /= 10;
        num = num * 10 + rem;
    }
    return num;
}

int beautiful(int l, int r, int k)
{
    int i, count = 0;
    for(i = l; i <= r; i++)
    {
        int diff = abs(i - reverse(i));
        if(diff % k == 0)
            count++;
    }
    return count;
}
int main()
{
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    printf("%d",beautiful(i, j, k));
    return 0;
}
