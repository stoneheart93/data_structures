#include<stdio.h>
#include<stack>
using namespace std;

int prcd(char symbol)
{
    switch(symbol)
    {
    	case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
    }
    return -1;
}
int isoperator(char symbol)
{
    switch(symbol)
    {
		case '+':
     	case '-':
     	case '*':
     	case '/':
     	case '^':
     	case '$':
     	case '(':
     	case ')': return 1;
     	default: return 0;
    }
}
int convert(char* infix, char* postfix)
{
    int symbol,j=0;
    stack<char> s;
    for(int i = 0; infix[i]; i++)
    {
        symbol = infix[i];
        if(!isoperator(symbol)) //operand
            postfix[j++] = symbol;
    	else if(symbol == '(')
            s.push(symbol);
        else if(symbol == ')')
    	{
            while(!s.empty() && s.top() != '(')
            {
                postfix[j++] = s.top();
                s.pop();
            }
        	if(!s.empty() && s.top() != '(')
                return -1;
        	else
            	s.pop(); //for removing (
        }
        else
        {
            while(!s.empty() && prcd(symbol) <= prcd(s.top()))
            {
                postfix[j++] = s.top();
                s.pop();
            }
        	s.push(symbol);
    	}
    }
    while(!s.empty())// adding the remaining contents on stack to postfix
    {
        postfix[j++] = s.top();
        s.pop();
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[20], postfix[20];
    printf("\nEnter the infix string: ");
    gets(infix);
    convert(infix, postfix);
    printf("\nThe postfix string: ");
    puts(postfix);
    return 0;
}

