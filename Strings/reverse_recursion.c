#include<stdio.h>

void revrec(char* str)
{
    if(*str)
    {
        revrec(str + 1);
        printf("%c", *str);
	}
}

int main()
{
    char str[10];
	scanf("%s", str);
	revrec(str);
    return 0;
}
