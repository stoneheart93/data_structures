// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/capicua-2/

#include<stdio.h>
#include<string.h>

int isCapicua(char* str)
{
    int n = strlen(str);
    for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
    {
        if(str[i] != str[j])
            return 0;
    }
    return 1;
}

int main()
{
    int tc;
    char str[20];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", &str);
        if(isCapicua(str))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
