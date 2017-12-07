#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int areRotations(char* str1,char* str2)
{
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    if(size1 != size2)
        return 0;
    char* temp = (char*)malloc(sizeof(char) * (2 * size1 + 1));
    temp[0] = '\0';
	void* ptr;
    strcat(temp, str1);
    strcat(temp, str1);
    ptr = strstr(temp, str2); // strstr returns NULL if the second string is NOT a substring of first string 
    if(ptr != NULL)
    	return 1;
    else
        return 0;
}
int main()
{
    char str1[10], str2[10];
    scanf("%s", str1);
    scanf("%s", str2);
    if(areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
