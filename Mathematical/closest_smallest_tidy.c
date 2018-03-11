#include<stdio.h>

char* closest_tidy(char str[])
{
	int len = strlen(str);
	int i, j;
    for(i = len - 2; i >= 0; i--)
    {
        if(str[i] > str[i+1])
        {
            (char)str[i]--;
    		for(j = i + 1; j < len; j++)
            	str[j] = '9';
        }
    }
    return str;
}

int main()
{
	char str[20];
	scanf("%s", str);
	printf("%s", closest_tidy(str));
	return 0;
}
