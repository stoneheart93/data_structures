#include<stdio.h>
#include<stdlib.h>

int isHappyUtil(char* str, int n)
{
    if(n == 1)
        return 0;
    int i;
    for(i = 0; i < n - 1; i++)
    {
        if(i == 0 && str[i] != str[i + 1])
            return 0;
        else if(str[i-1] != str[i] && str[i] != str[i+1])
            return 0;
    }
    return 1;
}

int isHappy(char* str, int n)
{
    int* count = (int*)calloc(26, sizeof(int));

    int i, underscore = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] == '_')
            underscore = 1;
        count[str[i] - 'A']++;
    }

    for(i = 0; i < 26; i++)
    {
        if(count[i] == 1)
            return 0;
        else if(!underscore && !isHappyUtil(str, n))
            return 0;
    }
    return 1;
}
int main()
{
    int tc, n;
    char* str = (char*)malloc(n * sizeof(char));
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        scanf("%s", str);
        if(isHappy(str, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

