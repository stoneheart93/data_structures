#include<stdio.h>
  
int myAtoi(char *str)
{
	int res = 0, sign = 1, i = 0; 
    if (str[0] == '-')
    {
        sign = -1;  
        i++;  
	}
    for (; str[i]; i++)
        res = res * 10 + str[i] - '0';
    return sign*res;
}
  
int main()
{
    char str[] = "-123";
    printf ("%d", myAtoi(str));
    return 0;
}

