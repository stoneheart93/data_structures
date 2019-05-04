#include<stdio.h>

int minDeletions(char* str1, char* str2)
{
    static int count[26];
    int i;
    for(i = 0; str1[i]; i++)
        count[str1[i] - 'a']++;

    for(i = 0; str2[i]; i++)
        count[str2[i] - 'a']--;
    
    int deletions = 0;
    for(i= 0; i < 26; i++)
    {
        deletions += count[i] < 0 ? -count[i] : count[i]; 
    }
    return deletions;
}

int main()
{
    char str1[10005], str2[10005];
    scanf("%s", str1);
    scanf("%s", str2);
    printf("%d", minDeletions(str1, str2));
    return 0;
}
