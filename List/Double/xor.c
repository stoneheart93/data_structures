#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* lrx;
};

struct node* XOR(struct node* a, struct node* b)  
{  
    return (struct node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  

void addatbeg(struct node** head)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &temp->data);
	temp->lrx = XOR(NULL, (*head));
	
	if((*head) != NULL)
	{
		struct node* next = XOR((*head)->lrx, NULL);
		(*head)->lrx = XOR(temp, next);
	}
	
	*head = temp;
}

void display(struct node* head)
{
	struct node* rider = head;
	struct node* prev = NULL;
	struct node* next;
	
	while(rider != NULL)
	{
		printf("%d-->", rider->data);
		
		next = XOR(prev, rider->lrx);
		
		prev = rider;
		rider = next;
	}
}

int main()  
{  
	int flag;
	struct node *head = NULL;  
    
    while(1)
    {
    	addatbeg(&head);
    	printf("Do you wish to insert?: ");
    	scanf("%d", &flag);
    	if(flag == 0)
    		break;
	}
    
	display(head);  
    return 0;  
}  
