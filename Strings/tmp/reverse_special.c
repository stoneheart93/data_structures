#include<stdio.h>
#include<string.h>

int alphabet(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void revspl(char* str)
{
	int l = 0, r = strlen(str) - 1;
    while(l < r)
    {
    	if(!alphabet(str[l]))
    		l++;
    	else if(!alphabet(str[r]))
    		r--;
    	else
    	{
    		swap(&str[l], &str[r]);
    		l++;
    		r--;
		}
	}
}

int main()
{
    char str[10];
	scanf("%s", str);
	revspl(str);
	printf("%s", str);
    return 0;
}
