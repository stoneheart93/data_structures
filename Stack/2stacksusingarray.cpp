#include<iostream>
using namespace std;
 
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
	twoStacks(int n)  // constructor
	{
       size = n;
       arr = new int[n];
       top1 = -1;
       top2 = size;
	}

	void push1(int x)	
	{
		if(top1 < top2 - 1)
		{
        	top1++;
        	arr[top1] = x;
		}
		else
			printf("Stack Overflow");    
	}
 
	void push2(int x)
	{
		if(top1 < top2 - 1)
		{
        	top2--;
        	arr[top2] = x;
		}
		else
           printf("Stack Overflow");
	}
 
	int topandpop1()
	{
    	if(top1 >= 0 )
		{
        	int x = arr[top1];
			top1--;
        	return x;
    	}
    	else
        	printf("Stack UnderFlow");
	}
 
	int topandpop2()
	{
    	if (top2 < size)
		{
        	int x = arr[top2];
        	top2++;
        	return x;
    	}
    	else
        	printf("Stack UnderFlow");
	}
};
 
int main()
{
	twoStacks ts(5);
    int num,choice;
    while(1)
    {
        printf("\n STACK MENU");
        printf("\n 1.Push into stack1");
        printf("\n 2.Top and Pop from stack1");
        printf("\n 3.Push into stack2");
        printf("\n 4.Top and Pop from stack2");
        printf("\n 5.Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\n Enter a number:");
                    scanf("%d",&num);
                    ts.push1(num);
                    break;
            case 2: printf("\n Top element: %d", ts.topandpop1());
                    break;
            case 3: printf("\n Enter a number:");
                    scanf("%d",&num);
                    ts.push2(num);
                    break;
            case 4: printf("\n Top element: %d", ts.topandpop2());
                    break;
            case 5: goto exit;
        }
    }
    exit:
    return 0;
} 
