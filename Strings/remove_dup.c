#include<stdio.h>
#define NO_OF_CHARS 256

void removeDups(char *str)
{
    static int count[NO_OF_CHARS];
    int ip_ind, res_ind = 0; 
    for(ip_ind = 0; str[ip_ind]; ip_ind++)
    {
        if(count[str[ip_ind]] == 0)
        {
    	    count[str[ip_ind]] = 1;
            str[res_ind++] = str[ip_ind];
        }
    }      
    str[res_ind] = '\0';   
}

int main()
{
    char str[10];
	scanf("%s", str);
    removeDups(str);
    printf("%s", str);
    return 0;
} 
