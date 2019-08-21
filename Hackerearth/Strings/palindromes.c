// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/palindromes-3/

#include<string.h>

int isPalindrome(char* str)
{
    int n = strlen(str);
    for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
    {
        if(str[i] != str[j])
            return 0;
    }
    return 1;
}

int isSame(char* str)
{
    for(int i = 1; str[i]; i++)
    {
        if(str[i] != str[0])
            return 0;
    }
    return 1;
}

int notPalindrome(char* str)
{
    if(isSame(str))
        return 0;
        
    int n = strlen(str);
    if(isPalindrome(str))
        return n - 1;
    else
        return n;
}

int main()
{
    char str[100005];
    scanf("%s", &str);
    printf("%d", notPalindrome(str));
    return 0;
}
