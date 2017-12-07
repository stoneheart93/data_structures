#include<stdio.h>
#define NO_OF_CHARS 256

void removeChar(char *str, char* mask)
{
    static int count[NO_OF_CHARS];
    int ip_ind, res_ind = 0;
	int i;
	for(i = 0; mask[i]; i++)
		count[mask[i]]++;
    for(ip_ind = 0; str[ip_ind]; ip_ind++)
    {
        if(count[str[ip_ind]] == 0)
        {
    	    str[res_ind++] = str[ip_ind];
        }
    }      
    str[res_ind] = '\0';
}

int main()
{
    char str[10], mask[10];
    scanf("%s", str);
    scanf("%s", mask);
    removeChar(str, mask);
    printf("%s", str);
    return 0;
} 
