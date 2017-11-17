#include<stdio.h>
#define NO_OF_CHARS 26

int isPanagram(char* str)
{
    static int count[NO_OF_CHARS];
    int i, index;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            index = str[i] - 'A';
        if(str[i] >= 'a' && str[i] <= 'z')
            index = str[i] - 'a';
        count[index] = 1;
    }
   	for(i = 0; i < 26; i++)
    {
    	if(count[i] == 0)
            return 0;
    }
    return 1;
}
int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog";
    if(isPanagram(str))
        printf("Panagram");
    else
        printf("Not panagram");
    return 0;
}
