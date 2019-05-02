#include<stdio.h>

int countWords(char* str)
{
    int i, count = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            count++;
    }
    return count + 1;
}

int main()
{
    char str[100005];
    scanf("%s", str);
    printf("%d", countWords(str));
    return 0;
}
