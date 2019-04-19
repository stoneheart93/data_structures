#include<stdio.h>
#include<cctype>
#include<string.h>
#include<stack>
using namespace std;

int evaluatePrefix(char *exp)
{
    stack<int> s;
    int exp_len = strlen(exp);
    for(int i = exp_len - 1; i >= 0; i--)
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
	printf("\nEnter the prefix expression: ");
	gets(exp);
	printf("%d", evaluatePrefix(exp));
    return 0;
}	
