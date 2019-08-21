// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/monk-teaches-palindrome/

#include<stdio.h>
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

int main()
{
    int tc;
    char str[100005];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", &str);
        if(isPalindrome(str))
        {
            printf("YES ");
            if(strlen(str) % 2 == 0)
                printf("EVEN\n");
            else
                printf("ODD\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
