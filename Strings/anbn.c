#include<stdio.h>

int isAnBn(char* str)
{
	int n = strlen(str);
	int i, j;

	for(i = 0; i < n; i++)
    {
    	if(str[i] != 'a')
        	break;
	}  
   
	if(i*2 != n)
    	return 0;
    	
	for(j = i; j < n; j++)
    {
    	if(str[j] != 'b')
        	return 0;
	}  
	return 1;
}
 
int main()
{
    char str[10];
    scanf("%s", str);
    if(isAnBn(str)) 
		printf("Yes");
	else
		printf("No");
	return 0;
}
