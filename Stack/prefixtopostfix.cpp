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
string prefixToPostfix(string prefix)
{
    stack<string> s;
    int prefix_length = prefix.size();
    
    for(int i = prefix_length - 1; i >= 0; i--)
    {
        if(isoperator(prefix[i]))
        {
        	string val1 = s.top();
			s.pop();
			string val2 = s.top();
			s.pop();	
			
			string temp = val1 + val2 + prefix[i];
			s.push(temp);
		}
		else
			s.push(string(1, prefix[i]));
    }
    return s.top();
}

int main()
{
    string prefix;
    printf("\nEnter the prefix string: ");
    cin >> prefix;
	printf("\nThe postfix string: ");
    cout << prefixToPostfix(prefix);
    return 0;
}

