#include<stdio.h>

int find(char* str)
{
    char* hack = "hackerrank";
    
    while(*str && *hack)
    {
        if(*str == *hack)
        {
            str++;
            hack++;
        }
        else
            str++;
    }
    if(*hack)
        return 0;
    else    
        return 1;
}

int main()
{
    int tc;
    char str[10005];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", str);
        if(find(str))
            printf("YES\n");
        else    
            printf("NO\n");
    }
    return 0;
}

