#include<stdio.h>
#include<stack>
using namespace std;

int findDupParenthesis(char* str)
{
    stack<char> s;
 
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == ')')
        {
        	char top = s.top();
            s.pop();
            if(top == '(')
            	return 1;
			else
            {
                while(top != '(')
                {
                    top = s.top();
                    s.pop();
                }
            }
        }
        else
        	s.push(str[i]);
    }
 	return 0;
 }
 
int main()
{
    char exp[20];
	printf("\nEnter the characters: ");
	gets(exp);
	if(findDupParenthesis(exp))
	    printf("duplicate paranthesis");
    else
        printf("no duplicate paranthesis");
    return 0;
}
