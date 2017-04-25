#include<stdio.h>
#define NO_OF_CHARS 256

int areAnagram(char* str1, char* str2)
{
    static int count[NO_OF_CHARS];
    int i;
    for(i = 0; str1[i] && str2[i]; i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    if(str1[i] || str2[i])
    	return 0;
    for(i = 0; i < NO_OF_CHARS; i++)
    {
        if(count[i])
        	return 0;
    }
    return 1;
}

int main()
{
    char str1[] = "abcd";
    char str2[] = "dacb";
    if(areAnagram(str1,str2))
    	printf("The two strings are anagram");
    else
        printf("The two strings are not anagram");
    return 0;
} 
