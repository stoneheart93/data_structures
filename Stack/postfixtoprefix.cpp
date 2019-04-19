#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int isoperator(char symbol)
{
    switch(symbol)
    {
		case '+':
     	case '-':
     	case '*':
     	case '/':
     	case '^': return 1;
     	default: return 0;
    }
}
string postfixToPrefix(string postfix)
{
    stack<string> s;
    int postfix_length = postfix.size();
    
    for(int i = 0; postfix[i]; i++)
    {
        if(isoperator(postfix[i]))
        {
        	string val1 = s.top();
			s.pop();
			string val2 = s.top();
			s.pop();	
			
			string temp = postfix[i] + val2 + val1;
			s.push(temp);
		}
		else
			s.push(string(1, postfix[i]));
    }
    return s.top();
}

int main()
{
    string postfix;
    printf("\nEnter the postfix string: ");
    cin >> postfix;
	printf("\nThe prefix string: ");
    cout << postfixToPrefix(postfix);
    return 0;
}

