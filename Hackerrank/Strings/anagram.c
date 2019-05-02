#include<stdio.h>

int changesAnagram(char* str)
{
    int* count = (int*)calloc(26, sizeof(int));
    int len = strlen(str);
    if(len % 2 != 0)
        return -1;
    
    int i, j;
    for(i = 0, j = len/2; j < len; i++, j++)
    {
        count[str[i] - 'a']++;
        count[str[j] - 'a']--;
    }

    int change = 0;
    for(i = 0; i < 26; i++)
    {
        if(count[i] > 0)
            change += count[i];
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
        printf("%d\n", changesAnagram(str));
    }
    return 0;
}

