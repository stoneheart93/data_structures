#include<stdio.h>
#include<stack>
using namespace std;

stack<int> sort_temp_stack(stack<int> input)
{
	stack<int> temp;
	while(!input.empty())
	{
		int element = input.top();
		input.pop();
		
		while(!temp.empty() && temp.top() > element)
		{
			int temp_element = temp.top();
			temp.pop();
			input.push(temp_element);
		}
		temp.push(element);
	}
	return temp;
}

int main()
{
	stack<int> input;
	
	int n, var;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &var);
		input.push(var);
	}
	
	stack<int> temp = sort_temp_stack(input);
	
	while(!temp.empty())
    {
        printf("%d ", temp.top());
        temp.pop();
    }

	return 0;
}
