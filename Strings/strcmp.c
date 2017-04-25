#include<stdio.h>
#include<stdlib.h>

int ic_strcmp(char* s1, char* s2)
{
    int i;
    for(i = 0; s1[i] && s2[i]; i++)
    {
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
        	continue;
        else
        	break;
    }
 
    if(s1[i] == s2[i])
    	return 0;
    else if((s1[i]|32) < (s2[i]|32)) 
        return -1;
    else
		return 1;
}
 
int main(void)
{
    printf("ret: %d\n", ic_strcmp("Geeks", "apple"));
    printf("ret: %d\n", ic_strcmp("", "ABCD"));
    printf("ret: %d\n", ic_strcmp("ABCD", "z"));
    printf("ret: %d\n", ic_strcmp("ABCD", "abcdEghe"));
    printf("ret: %d\n", ic_strcmp("GeeksForGeeks", "gEEksFORGeEKs"));
    printf("ret: %d\n", ic_strcmp("GeeksForGeeks", "geeksForGeeks"));
    return 0;
}

