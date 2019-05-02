#include<stdio.h>

int changedSOS(char* str)
{
    int len = strlen(str);
    int i, count = 0;

    for(i = 0; i < len - 2; i = i+3)
    {
        if(str[i] != 'S')
            count++;
        if(str[i+1] != 'O')
            count++;
        if(str[i+2] != 'S')
            count++;
    }
    return count;
}

int main()
{
    char str[105];
    scanf("%s", str);
    printf("%d", changedSOS(str));
    return 0;
}

