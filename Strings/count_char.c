#include<stdio.h>

void count(char* str)
{
    int upper = 0, lower = 0, number = 0, special = 0;
    int i;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            lower++;
        else if(str[i] >= '0' && str[i] <= '9')
            number++;
        else
            special++;
    }
    printf("\nUpper case letters: %d", upper);
    printf("\nLower case letters: %d", lower);
    printf("\nNumber: %d", number);
    printf("\nSpecial characters: %d", special);
}
 
int main()
{
    char str[20];
    gets(str);
    count(str);
    return 0;
}

