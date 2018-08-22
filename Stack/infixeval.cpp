#include<stdio.h>
#include<cctype>
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
int applyOp(int a, int b, char op)
{
    switch(op)
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
int evaluateInfix(char *exp)
{
	stack<int> s;
    stack<char> ops;
    for(int i = 0; exp[i]; i++)
    {
    	if(isdigit(exp[i]))
            s.push(exp[i]-'0');
        else if(exp[i] == '(')
        	ops.push(exp[i]);
        else if(exp[i] == ')')
        {
        	while(!ops.empty() && ops.top() != '(')
        	{
	            int val2 = s.top();
	            s.pop();
	            int val1 = s.top();
	            s.pop();
	            char op = ops.top();
	            ops.pop();
	            
	            s.push(applyOp(val1, val2, op));
	        }
	        ops.pop();
        }
        else
        {
            while(!ops.empty() && prcd(exp[i]) <= prcd(ops.top()))
            {
            	int val2 = s.top();
	            s.pop();
	            int val1 = s.top();
	            s.pop();
	            char op = ops.top();
	            ops.pop();
	            
	            s.push(applyOp(val1, val2, op));
	        }
	        ops.push(exp[i]);
	    }
	}
	    
	while(!ops.empty())
    {
        int val2 = s.top();
	    s.pop();
		int val1 = s.top();
	    s.pop();
	    char op = ops.top();
		ops.pop();
	            
	    s.push(applyOp(val1, val2, op));
	}
	
    return s.top();
}

int main()
{
    char exp[20];
	printf("\nEnter the infix expression: ");
	gets(exp);
	printf("%d", evaluateInfix(exp));
    return 0;
}	
