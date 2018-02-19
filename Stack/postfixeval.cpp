#include<stdio.h>
#include<cctype>
#include<stack>
using namespace std;

int evaluatePostfix(char *exp)
{
    stack<int> s;
    for(int i = 0; exp[i]; i++)
    {
    	if(isdigit(exp[i]))
            s.push(exp[i]-'0');
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch(exp[i])
            {
                case '+': s.push(val2 + val1);
                          break;
                case '-': s.push(val2 - val1); 
                          break;
            	case '*': s.push(val2 * val1); 
                          break;
                case '/': s.push(val2/val1);   
                          break;
            }
        }
    }
    return s.top();
}

int main()
{
    char exp[20];
	printf("\nEnter the postfix expression: ");
	gets(exp);
	printf("%d", evaluatePostfix(exp));
    return 0;
}	
