#include<stdio.h>

int isPalindromeAnagram(char* str)
{
    static int count[26];
    int i;
    int odd_frequency = 0;
    for(i = 0; str[i]; i++)
        count[str[i] - 'a']++;
    for(i = 0; i < 26; i++)
    {
        if(count[i] % 2 != 0)
            odd_frequency++;
    }
    return ((odd_frequency > 1) ? 0 : 1);
}

int main()
{
    char str[100005];
    scanf("%s", str);
    if(isPalindromeAnagram(str))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

