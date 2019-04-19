#include<stdio.h>
#define MAXSIZE 20

int top = -1;
int stack[MAXSIZE];

int isEmpty()
{
    if(top == -1)
    	return 1;
    else
        return 0;
}

int isFull()
{
    if(top == MAXSIZE-1)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if(isFull())
        printf("\n Full stack");
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if(isEmpty())
        printf("\n Empty stack");
    else
        top--;
}

int topp()
{
	if(isEmpty())
        printf("\n Empty stack");
    else
	    return stack[top];
}

int topandpop()
{
    if(isEmpty())
        printf("\n Empty Stack");
    else
    {
        int element = stack[top];
        top--;
        return element;
    }
} 

void display()
{
    if(isEmpty())
        printf("\n Empty Stack");
    else
    {
    	int i;
        for(i = top; i >= 0;i--)
    		printf("\n%d ",stack[i]);
    }
}

int main()
{
    int num,choice;
    while(1)
    {
        printf("\n STACK MENU");
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Check whether stack is empty");
        printf("\n 4.Check whether stack is full");
        printf("\n 5.Top");
        printf("\n 6.Top and Pop");
        printf("\n 7.Display");
        printf("\n 8.Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\n Enter a number:");
                    scanf("%d",&num);
                    push(num);
                    break;
            case 2: pop();
                    break;
            case 3: if(isEmpty())
                        printf("\n Stack is empty");
                    else
                        printf("\n Stack is not empty");
                    break;
        	case 4: if(isFull())
                        printf("\n Stack is full");
                    else
                    	printf("\n Stack is not full");
                    break;
            case 5: printf("\n Top element: %d",topp());
                    break;
            case 6: printf("\n Top element: %d",topandpop());
                    break;
            case 7: display();
                    break;
            case 8: goto exit;
        }
    }
    exit:
    return 0;
} 
