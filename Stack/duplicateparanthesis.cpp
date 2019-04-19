#include<stdio.h>
#include<stack>
using namespace std;

int findDupParenthesis(char* exp) // assume it is balanced
{
    stack<char> s;
 
    for(int i = 0; exp[i]; i++)
    {
        if(exp[i] == ')')
        {
        	int count = 0;
            while(s.top() != '(') // no need of checking stack empty, since it is assumed that the exp is balanced
            {
            	count++;
             	s.pop();
            }
            if(count == 0)
            	return 1;
        }
        else
        	s.push(exp[i]);
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
