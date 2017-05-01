#include<stdio.h>
#include<stack>
using namespace std;

int isMatchingPair(char open, char close)
{
	if(open == '(' && close == ')')
    	return 1;
	else if(open == '{' && close == '}')
    	return 1;
	else if(open == '[' && close == ']')
    	return 1;
	else
    	return 0;
}
int isExpressionBalanced(char* exp)
{
	stack<char> s;
	for(int i = 0; exp[i]; i++)
	{
	    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        	s.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(s.empty())
                return 0;
            if(!isMatchingPair(s.top(), exp[i]))
                return 0;
        	else
            	s.pop();
        }
    }
	if(s.empty())
        return 1;
    else
       return 0;
}
int main()
{
    char exp[20];
	printf("\nEnter the characters: ");
	gets(exp);
	if(isExpressionBalanced(exp))
	    printf("balanced");
    else
        printf("not balanced");
    return 0;
}	
