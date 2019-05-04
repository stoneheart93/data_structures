#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gemStones(char* list[], int n)
{
    int count[26], mark[26];
    int i, j;
    
    memset(count, 0, sizeof(count));
    
    for(i = 0; i < n; i++)
    {
        memset(mark, 0, sizeof(mark));

        for(j = 0; list[i][j]; j++)
            mark[list[i][j] - 'a'] = 1;
        
        for(j = 0; j < 26; j++)
            count[j] += mark[j];
    }

    int gem = 0;
    for(i = 0; i < 26; i++)
    {
        if(count[i] == n)
            gem++;
    }
    return gem;
}

int main()
{
    int n, i;
    scanf("%d", &n);

    char** list = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
        list[i] = (char*)malloc(100 * sizeof(char));

    for(i = 0; i < n; i++)
    {
        scanf("%s", list[i]);
    }
    printf("%d", gemStones(list, n));
    return 0;
}

