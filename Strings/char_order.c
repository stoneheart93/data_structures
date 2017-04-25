#include<stdio.h>
#define NO_OF_CHARS 256
 
int checkPattern(char* str, char* pat)
{
    static int label[NO_OF_CHARS];
    
    int i, order = 1;
    for(i = 0; pat[i]; i++)
    {
        label[pat[i]] = order;
 		order++;
    }
 
    int last_order = 0;
    for(i = 0; str[i]; i++)
    {
        if (label[str[i]] != 0)
        {
            if (label[str[i]] < last_order)
                return 0;
 	        last_order =  label[str[i]];
        }
    }
 	return 1;
}
 
int main()
{
	char str[30];
	char pattern[30];
    scanf("%s %s", str, pattern);
    if(checkPattern(str, pattern))
    	printf("String follows order of characters defined by a pattern");
    else
    	printf("Doesnt follow");
    return 0;
}

