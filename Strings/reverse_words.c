#include<stdio.h>

void reverse(char* begin, char* end)
{
    char temp;
    while(begin < end)
    {
        temp = *begin;
        *begin++ = *end;
    	*end-- = temp;
    }
}
void reverseWords(char* s)
{
    char* word_begin = s;
    char* temp = s; 
    while(*temp)
    {
        if(*temp == '\0')
        {
            reverse(word_begin, temp-1);
        }
        else if(*temp == ' ')
        {
        	reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
        temp++;
    }
    reverse(s, temp-1);
}

int main()
{
  	char str[100];
	gets(str);
  	reverseWords(str);
  	printf("%s", str);
 	return 0;
}
