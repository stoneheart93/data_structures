#include<stdio.h>
 
char findExtraChar(char* str1, char* str2)
{
    int res = 0, i;

    for(i = 0; str1[i]; i++) 
        res ^= str1[i];
    
    for(i = 0; str2[i]; i++) 
        res ^= str2[i];
   
    return ((char)(res));
}
 
int main()
{
    char str1[10], str2[10];
    scanf("%s", str1);
	scanf("%s", str2);
	printf("%c", findExtraChar(str1, str2));
    return 0;
}
