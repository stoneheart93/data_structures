#include<stdio.h>
#include<string.h>

int isEqual(char* str)
{
    int n = strlen(str);
 
    int num = 0, x = 1, i;
    for(i = n-1; i >= 0; i--)
    {
        if(str[i] >= '0' &&  str[i]  <= '9')
        {
            num = (str[i] - '0') * x + num;
            x = x * 10;
        }
        else 
			break;
    }
    return num == i+1;
}

int main()
{
	char str[20] = "geeksforgeeks13";
    printf("%d", isEqual(str));
    return 0;
}

