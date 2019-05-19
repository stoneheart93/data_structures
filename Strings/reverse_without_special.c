#include<stdio.h>

int isAlphabet(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char* reverse(char* str)
{
	int l = 0;
	int h = strlen(str) - 1;
	while(l < h)
	{
		if(!isAlphabet(str[l]))
			l++;
		else if(!isAlphabet(str[h]))
			h--;
		else
		{
			char temp = str[l];
			str[l] = str[h];
			str[h] = temp;
			l++;
			h--;
		}
	}
	return str;
}

int main()
{
	char str[100];
	scanf("%s", str);
	printf("%s", reverse(str));
	return 0;
}
