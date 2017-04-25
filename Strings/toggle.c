#include<stdio.h>
#include<string.h>

char* toggle(char* str)
{
	int i;
	for(i = 0; str[i]; i++)
	{
		if ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
			str[i] = str[i] ^ 32;
	}
	return str;
}

int main()
{
	char str[10];
    scanf("%s", str);
    printf("%s", toggle(str));
    return 0;
}
