#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* column(int n)
{
    char* str = (char*)malloc(sizeof(char) * 50);
    int i = 0, rem;
    while(n > 0)
    {
        rem = n % 26;
        if (rem == 0)
        {
            str[i++] = 'Z';
            n = (n / 26) - 1;
        }
        else 
		{
            str[i++] = (rem - 1) + 'A';
            n = n / 26;
        }
    }
    str[i] = '\0';
	return strrev(str);
}
 
int main()
{
	int n;
	scanf("%d", &n);
	printf("%s", column(n));
	return 0;
}
