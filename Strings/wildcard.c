#include<stdio.h>

int match(char* first, char* second)
{
    if(*first == '\0' && *second == '\0')
        return 1;
    if(*first == '*' && *(first + 1) != '\0' && *second == '\0')
        return 0;
    if(*first == '?' || *first == *second)
        return match(first + 1, second + 1);
    if(*first == '*')
        return match(first + 1, second) || match(first, second + 1);
    return 0;
}

int main()
{
    char str1[] = "g*k?";
    char str2[] = "geeks";
    if(match(str1, str2))
        printf("The two strings match");
    else
        printf("The two strings do not match");
    return 0;
}
