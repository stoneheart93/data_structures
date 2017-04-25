#include<stdio.h>

void removeSpaces(char* str)
{
    int count = 0, i;
    for(i = 0; str[i]; i++)
    {
    	if(str[i] != ' ')
    		str[count++] = str[i];
    }
    str[count] = '\0';
}

int main()
{
    char str[20];
    gets(str);
    removeSpaces(str);
    printf("%s", str);
    return 0;
}
