#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

void reverse(char* str)
{
    int n = strlen(str);
    stack<char> s;
    
    for(int i = 0; i < n; i++)
        s.push(str[i]);
 
    for(int i = 0; i < n; i++)
    {
    	str[i] = s.top();
    	s.pop();
    }
}
 
int main()
{
    char str[50];
    printf("\nEnter a string: ");
	gets(str);
    reverse(str);
    printf("Reversed string is %s", str);
    return 0;
}
