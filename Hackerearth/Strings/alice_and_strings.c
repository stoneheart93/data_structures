// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/aliceandstrings-9da62aa7/

#include<stdio.h>
#include<string.h>
#include<limits.h>

int isCompatible(char* str1, char* str2)
{
    int count[26] = {0};
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    if(m != n)
        return 0;
    
    int prev = INT_MAX;
    for(int i = 0; str1[i] && str2[i]; i++)
    {
        int diff = str2[i] - str1[i];
        if(diff > prev)
            return 0;
        prev = diff;
    }
    return 1;
}

int main()
{
    char str1[1000005], str2[1000005];
    scanf("%s%s", &str1, &str2);
    if(isCompatible(str1, str2))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
