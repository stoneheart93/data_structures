#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
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
     	case '^': return 1;
     	default: return 0;
    }
}
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix;
    
    for(int i = 0; infix[i]; i++)
    {
        if(!isoperator(infix[i])) //operand
            postfix += infix[i];
    	else if(infix[i] == '(')
            s.push(infix[i]);
        else if(infix[i] == ')')
    	{
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
        	s.pop(); //for removing (
        }
        else
        {
            while(!s.empty() && prcd(infix[i]) <= prcd(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
        	s.push(infix[i]);
    	}
    }
    while(!s.empty())// adding the remaining contents on stack to postfix
    {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

string infixToPrefix(string infix) 
{ 
    int l = infix.size(); 
    reverse(infix.begin(), infix.end()); 
  
    for(int i = 0; infix[i]; i++) 
	{ 
    	if(infix[i] == '(') 
	        infix[i] = ')'; 
        else if (infix[i] == ')') 
		    infix[i] = '('; 
    } 
  
    string prefix = infixToPostfix(infix); 
    reverse(prefix.begin(), prefix.end());   
    return prefix; 
} 

int main()
{
    string infix;
    printf("\nEnter the infix string: ");
    cin >> infix;
	printf("\nThe prefix string: ");
    cout << infixToPrefix(infix);
    return 0;
}

