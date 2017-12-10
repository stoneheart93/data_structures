#include<stdio.h>

int oppositeSigns(int x,int y)
{
    return ((x ^ y) < 0);
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
	if(oppositeSigns(x,y))
        printf("Signs are opposite");
    else
        printf ("Signs are not opposite");
    return 0;
}
