// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/marut-and-strings-4/

#include<stdio.h>

int min(int a, int b)
{
    return (a < b ? a : b);
}

void goodString(char* str)
{
    int upper = 0, lower = 0;
    for(int i = 0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            lower++;
    }
    if(upper == 0 && lower == 0)
        printf("Invalid Input\n");
    else if((upper == 0 && lower != 0) || (upper != 0 && lower == 0))
        printf("0\n");
    else
        printf("%d\n", min(upper, lower));
}

int main()
{
    int tc;
    char str[105];
    scanf("%d", &tc);
    if(tc > 10 || tc < 1)
    {
        printf("Invalid Test\n");
        return 0;
    }
    while(tc--)
    {
        scanf("%s", &str);
        if(strlen(str) > 100 || strlen(str) < 1)
        {
            printf("Invalid Input\n");
            return 0;
        }
        goodString(str);
    }
    return 0;
}
