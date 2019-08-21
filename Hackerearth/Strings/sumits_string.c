// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/sumits-string/description/

#include<stdio.h>

int isString(char* str)
{
    int diff;
    int n = strlen(str);
    
    for(int i = 0; i < n - 1; i++)
    {
        if(str[i] == 'z' && str[i + 1] == 'a')
            diff = 1;
        else if(str[i] == 'a' && str[i + 1] == 'z')
            diff = 1;
        else
            diff = str[i]  - str[i + 1];
        if(abs(diff) != 1)
            return 0;
    }
    return 1;
}

int main()
{
    int tc;
    char str[255];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", &str);
        if(isString(str))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

