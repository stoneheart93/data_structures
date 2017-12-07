#include<stdio.h>
#define NO_OF_CHARS 256

int firstNonRepeating(char* str)
{
    static int count[NO_OF_CHARS];
    int i, index = -1;
    for(i = 0; str[i]; i++)
    	count[str[i]]++;
    for(i = 0; str[i]; i++)
    {
    	if(count[str[i]] == 1) 
        {
        	index = i;
            break;
		}
    }
    return index;
}

int main()
{
    char str[20];
    scanf("%s", str);
    int index = firstNonRepeating(str);
    if(index == -1)
        printf("String is empty and all are repeating");
    else
        printf("First non-repeating character is %c", str[index]);
    return 0;
}
