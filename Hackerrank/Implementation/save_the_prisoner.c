#include<stdio.h>

int main()
{
    int tc, n, m, s;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d%d%d", &n, &m, &s);
        int d = (s + m - 1) % n;
        printf("%d\n", d ? d : n);
    }
    return 0;
}
