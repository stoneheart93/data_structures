#include<stdio.h>
#include<stack>
using namespace std;

int findMaxLen(char* exp)
{
    stack<int> s;
    s.push(-1); 
    int result = 0;
	
	for(int i = 0; exp[i]; i++)
    {
        if(exp[i] == '(')
        	s.push(i);
        else 
        {
            s.pop();
			if(!s.empty())
            	result = max(result, i - s.top());
 			else 
				s.push(i);
        }
    }
    return result;
}

int main()
{
    char exp[20];
	printf("\nEnter the characters: ");
	gets(exp);
	printf("%d", findMaxLen(exp));
    return 0;
}


