#include<stdio.h>
#define NO_OF_CHARS 256

char getMaxOccuringChar(char *str)  
{
	static int count[NO_OF_CHARS];
    int i, max_index = 0;
    for(i = 0; str[i]; i++)
        count[str[i]]++;
    for(i = 1; i < NO_OF_CHARS; i++)
    {
    	if(count[i] > count[max_index])
        	max_index = i;
    }
    return max_index;
}

int main()
{
    char str[10];
    scanf("%s", str);
	printf("Max occuring character: %c", getMaxOccuringChar(str));
    return 0;
}
