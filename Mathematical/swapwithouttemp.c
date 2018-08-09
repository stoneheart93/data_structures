#include<stdio.h>

void swap(int* a, int* b)
{
	if(a == b)
		return;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
