#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* encode(char* src)
{     
	int i, j = 0, k, rLen;
  	char count[50];
  	int len = strlen(src);
   
  	char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));
  	
	for(i = 0; i < len; i++)
  	{	
 		dest[j++] = src[i];
     	rLen = 1;     
    	while(i + 1 < len && src[i] == src[i+1])
    	{
      		rLen++;
      		i++;
    	}   
     
    	sprintf(count, "%d", rLen);
 		
		for(k = 0; count[k]; k++)
    	{ 
      		dest[j++] = count[k]; 
    	} 
  	}		  
 
  	dest[j] = '\0';
  	return dest;
}     
 
int main()
{
    char str[20];
    scanf("%s", str);
	printf("%s", encode(str));
    return 0;
}
