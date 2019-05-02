#include<stdio.h>

int minOperations(char* str)
{
    int n = strlen(str);
    if(n == 1)
        return 0;
    
    int i, count = 0;
    for(i = 1; i < n; i++)
    {
        char temp = str[i-1];
        while(str[i] == temp)
        {
            count++;
            i++;
        }
    }
    return count;
}

int main()
{
    int tc;
    char str[100005];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", str);
        printf("%d\n", minOperations(str));
    }
    return 0;
}
