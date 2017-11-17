#include<stdio.h>
#include<string.h>

void stringFilter(char* str)
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
}

int main()
{
    char str[10];
    scanf("%s", str);
    stringFilter(str);
    printf("%s", str);
    return 0;
}
