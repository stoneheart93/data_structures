#include<stdio.h>

void removeSpaces(char* str)
{
    int index = 0, i;
    for(i = 0; str[i]; i++)
    {
    	if(str[i] != ' ')
    		str[index++] = str[i];
    }
    str[index] = '\0';
}

int main()
{
    char str[20];
    gets(str);
    removeSpaces(str);
    printf("%s", str);
    return 0;
}
