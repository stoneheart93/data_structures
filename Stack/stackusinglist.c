#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start = NULL, *rider;

void push(int value)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    
    rider = start;
    if(rider == NULL)
    	start=temp;
    else
    {
        while(rider->next != NULL)
            rider = rider->next;
        rider->next=temp;
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("\n Empty stack");
    	return;
    }
	
	rider = start;
	if(rider->next == NULL)
    {
        struct node* temp = rider;
        free(temp);
        start = NULL;
    }
    else
    {
        while(rider->next->next != NULL)
            rider = rider->next;
        struct node* temp = rider->next;
        rider->next = NULL;
        free(temp);
    }
}

int isEmpty()
{
    if(start == NULL)
        return 1;
    else
        return 0;
}

int topp()
{
	if(isEmpty())
    	printf("\nEmpty Stack");
    else
    {
	    rider = start;
	    while(rider->next!=NULL)
	        rider = rider->next;
	    return rider->data;
	}
}

int topandpop()
{
    if(isEmpty())
    	printf("\nEmpty Stack");
    else
    {
        rider = start;
        while(rider->next != NULL)
            rider = rider->next;
        int element = rider->data;
        pop();
        return element;
    }
}

void display()
{
    rider = start;
    while(rider != NULL)
    {
        printf("%d\n", rider->data);
        rider = rider->next;
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
        printf("\n 4.Top");
        printf("\n 5.Top and Pop");
        printf("\n 6.Display");
        printf("\n 7.Exit");
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
            case 4: printf("\n Top element: %d",topp());
                    break;
            case 5: printf("\n Top element: %d",topandpop());
                    break;
            case 6: display();
                    break;
            case 7: goto exit;
        }
    }
    exit:
    return 0;
} 
