#include<stdio.h>
#define OUT 1
#define IN 2

int countWords(char* str)
{
    int state = OUT;
    int wc = 0;  
    while(*str)
    {
    	if(*str == ' ' || *str == '\n' || *str == '\t')
        	state = OUT;
        else if(state==OUT)
        {
            state=IN;
            wc++;
        }
        str++;
    }
    return wc;
}

int main()
{
    char str[20];
    gets(str);
    printf("%d", countWords(str));
    return 0;
}
