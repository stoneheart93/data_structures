#include<stdio.h>

int panagram(char* str)
{
    static int count[26];
    int i;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            count[str[i] - 'A'] = 1
        else if(str[i] >= 'a' && str[i] <= 'z')
            count[str[i] - 'a'] = 1;
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
    char str[1005];
    scanf("%[^\n]s", str);
    if(panagram(str))
        printf("pangram");
    else
        printf("not pangram");
    return 0;
}
