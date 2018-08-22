#include<stdio.h>
#include<stack>
using namespace std;

int findDupParenthesis(char* str) // assume it is balanced
{
    stack<char> s;
 
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == ')')
        {
        	char element = s.top();
            s.pop();
            
            int count = 0;
            while(element != '(') // no need of checking stack empty, since it is assumed that the exp is balanced
            {
            	count++;
                element = s.top();
             	s.pop();
            }
            if(count == 0)
            	return 1;
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
