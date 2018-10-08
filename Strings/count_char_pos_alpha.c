#include<stdio.h>

int findCount(char* str) 
{ 
    int result = 0; 
	int i;

    for(i = 0; str[i]; i++) 
	{
		if(i == str[i]-'a' || i == str[i]-'A') 
            result++; 
    }
    return result; 
} 

int main()
{
	char str[100];
	scanf("%s", str);
	printf("%d", findCount(str));
	return 0;
}
