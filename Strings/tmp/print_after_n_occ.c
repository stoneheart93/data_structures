#include<stdio.h>
#include<string.h>

void printString(char* str, char c, int count)
{
	int occ = 0;
	int i, j;
	
	if(count == 0)
	{
		printf("%s", str);
		return;
	}
	
	for(i = 0; str[i]; i++)
	{
		if(str[i] == c)
			occ++;
		if(occ == count)
			break;		
	}
	if(i < strlen(str) - 1)
	{
		for(j = i + 1; str[j]; j++)
			printf("%c", str[j]);
	}
	else
		printf("Empty string");
}

int main()
{
    char str[20];
    char c;
    int n;
	gets(str);
	scanf("%c", &c);
	scanf("%d", &n);
	printString(str, c, n);
    return 0;
}
