#include<iostream>
#include<stack>
using namespace std;
 
class maxStack
{
	stack<int> mainStack;
	stack<int> maxStack;
public:
	void push(int x)	
	{
		mainStack.push(x);
		if(mainStack.size() == 1)
        {
            maxStack.push(x);
            return;
        }
 
        if(x > maxStack.top())
            maxStack.push(x);
        else
            maxStack.push(maxStack.top());
    }
  
	void pop()
	{
		mainStack.pop();
		maxStack.pop();
    }
 
	int getMax()
	{
    	return maxStack.top();
	}
};
 
int main()
{
	maxStack ms;
	int num,choice;
    while(1)
    {
        printf("\n STACK MENU");
        printf("\n 1.Push into stack");
        printf("\n 2.Pop from stack");
        printf("\n 3.Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\n Enter a number:");
                    scanf("%d",&num);
                    ms.push(num);
                    printf("Max: %d", ms.getMax());
                    break;
            case 2: ms.pop();
					printf("Max: %d", ms.getMax());
                    break;
            case 3: goto exit;
        }
    }
    exit:
    return 0;
} 
