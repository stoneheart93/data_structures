#include<stdio.h>
#include<string.h>
#include<string.h>

char* stringFilter(char* str)
{
    int n = strlen(str);
    int i = -1, j = 0; 
    
	while(j < n)
    {
        if(j < n-1 && str[j] == 'a' && str[j + 1] == 'c')
            j += 2;
		else if(str[j] == 'b')
            j++;
		else if(i >= 0 && str[j] == 'c' && str[i] == 'a')
        {
        	i--;
        	j++;
		}    
		else
            str[++i] = str[j++];
    }
    str[++i] = '\0';
    return str;
}

int main()
{
    char str[10];
    scanf("%s", str);
    printf("%s",stringFilter(str));
    return 0;
}
