#include<stdio.h>
#define NO_OF_CHARS 256

void printDups(char* str)
{
    static int count[NO_OF_CHARS];
	int i;
    for(i = 0; str[i]; i++)
        count[str[i]]++;
    for(i = 0; i < NO_OF_CHARS; i++)
    {
        if(count[i] > 1)
            printf("%c, Count = %d\n", i, count[i]);
    }
}

int main()
{
    char str[10];
    scanf("%s", str);
    printDups(str);
    return 0;
} 
