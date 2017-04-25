#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int check_char(char* str, int i, int j)
{
    int n;
    
	for(n = 0; str[n]; n++);
	
	if(str[i % n] == str[j % n])
		return 1;
	else
		return 0;
}
 
int main()
{
    char* str = "geeksforgeeks" ;
    printf("%d", check_char(str, 0, 8));
    return 0;
}
