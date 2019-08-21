// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/print-first-occurence/

#include<stdio.h>

void removeDup(char* str)
{
    int count[26] = {0};
    int j = 0;
    for(int i = 0; str[i]; i++)
    {
        if(count[str[i] - 'a'] == 0)
            str[j++] = str[i];
        count[str[i] - 'a'] = 1;
    }
    str[j] = '\0';
}

int main()
{
    int tc;
    char str[205];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", &str);
        removeDup(str);
        printf("%s\n", str);
    }
    return 0;
}
