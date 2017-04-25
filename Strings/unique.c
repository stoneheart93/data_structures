#include<stdio.h>
#define NO_OF_CHARS 256

int isUnique(char* str)
{
    static int count[256];
    int i;
    for(i = 0; str[i]; i++)
    {
        if(count[str[i]])
            return 0;
        count[str[i]] = 1;
    }
    return 1;
}

int main()
{
    char str[10];
    scanf("%s", str);
	if(isUnique(str))
        printf("Unique");
    else
        printf("Not unique");
	return 0;
}
