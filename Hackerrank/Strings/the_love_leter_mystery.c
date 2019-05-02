#include<stdio.h>
#include<string.h>

int changesPalindrome(char* str)
{
    int n = strlen(str);
    int change = 0;
    int i = 0, j = n - 1;
    
    while(i < j)
    {
        int start = str[i] - 'a';
        int end = str[j] - 'a';
        change += abs(start - end);
        i++;
        j--;
    }
    
    return change;
}

int main()
{
    int tc;
    char str[10005];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", str);
        printf("%d\n", changesPalindrome(str));
    }
    return 0;
}
