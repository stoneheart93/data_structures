#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256

int stringConstruction(char* str)
{
    int i;
    int count[NO_OF_CHARS];s
    memset(count, 0, sizeof(count));
   
    for(i = 0; str[i]; i++)
        count[str[i]] = 1;
        
    int c = 0;
    for(i = 0; i < NO_OF_CHARS; i++)
    {
        if(count[i] == 1)
            c++;
    }
    return c;
}

int main()
{
    char str[100005];
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
    	scanf("%s", str);
        printf("%d\n", stringConstruction(str));
    }
    return 0;
}
