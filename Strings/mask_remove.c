#include<stdio.h>
#define NO_OF_CHARS 256

char *removeChar(char *str, char* mask)
{
    static int count[256];
    int ip_ind, res_ind = 0;
	int i;
	for(i = 0; mask[i]; i++)
		count[mask[i]]++; 
    for(ip_ind = 0; str[ip_ind]; ip_ind++)
    {
        if(count[str[ip_ind]] == 0)
        {
    	    str[res_ind] = str[ip_ind];
            res_ind++;         
        }
    }      
    str[res_ind] = '\0';   
    return str;
}

int main()
{
    char str[10], mask[10];
    scanf("%s", str);
    scanf("%s", mask);
    printf("%s", removeChar(str, mask));
    return 0;
} 
