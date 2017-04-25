#include<stdio.h>

void swapThree(int* a, int* b, int* c)
{
    *a = *a ^ *b ^ *c;
    *b = *a ^ *b ^ *c;
    *c = *a ^ *b ^ *c;
	*a = *a ^ *b ^ *c;
}
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    swapThree(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}
