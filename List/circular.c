#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void addatbeg(struct node *head)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the data to be inserted in the beginning: ");
	scanf("%d", &temp->data);
	temp->next = head->next;
	head->next = temp;
}

void addatmid(struct node *head)
{
	struct node *rider = head;
	int num;
	printf("\n Enter the number before which the value to be inserted: ");
	scanf("%d", &num);
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the value to be inserted in the middle: ");
	scanf("%d", &temp->data);
	while(rider->next->data != num)
		rider = rider->next;
	temp->next = rider->next;
	rider->next = temp;
}

void addatend(struct node *head)
{
	struct node *rider = head->next;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the data to be inserted at the end: ");
	scanf("%d", &temp->data);
	while(rider->next != head)
		rider = rider->next;
	temp->next = head;
	rider->next = temp;
}

void sorted_insert(struct node* head)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data to be inserted in sorted way: ");
    scanf("%d", &temp->data);
    struct node *rider = head->next;
    if(rider == NULL)
    {
        temp->next = head;
        head->next = temp;
    }
    else if(temp->data <= rider->data)
    {
    	temp->next=head->next;
	    head->next=temp;
    }
    else
    {
        while(rider->next != head && temp->data > rider->next->data)
        	rider = rider->next;
        temp->next = rider->next;
        rider->next = temp;
    }
}

void delatbeg(struct node *head)
{
	struct node *temp = head->next;
	head->next = temp->next;
	free(temp);
}

void delatmid(struct node *head)
{
    struct node *rider = head;  
	int num;
	printf("\n Enter the number to be deleted: ");
	scanf("%d", &num);
	while(rider->next->data != num)
    	rider=rider->next;
	struct node *temp = rider->next;
	rider->next = temp->next;
	free(temp);
}

void delatend(struct node *head)
{
	struct node *rider = head->next;
	while(rider->next->next != head)
    	rider = rider->next;
	struct node *temp = rider->next;
	rider->next = head;
	free(temp);
}

int count(struct node *head)
{
    struct node *rider = head->next;
    int count = 0;
    while(rider != head) 
	{
        rider = rider->next;
		count++;
    }
	return count;
}

void display(struct node *head)
{
	struct node *rider = head->next;
	while(rider != head)
	{
		printf("--->%d",rider->data);
		rider = rider->next;
	}

}

void splitList(struct node *head, struct node **head1, struct node **head2)
{
	if(head->next == NULL)
    	return;
  
	struct node *slowptr = head->next;
	struct node *fastptr = head->next; 
   		
  	// slowptr -> middle, fastptr -> last 
	while(fastptr->next != head && fastptr->next->next != head) 
	{
    	fastptr = fastptr->next->next;
		slowptr = slowptr->next;
	}  
	if(fastptr->next->next == head)
		fastptr = fastptr->next;      
   
   	*head1 = head;    
      
	if(head->next->next != head)
	{
		*head2 = (struct node*)malloc(sizeof(struct node));
		(*head2)->next = slowptr->next;
    	fastptr->next = *head2;
	}
	
	slowptr->next = *head1;       
}

void exchangeNodes(struct node *head)
{
    struct node *rider = head->next;
    
    while(rider->next->next != head)
    	rider = rider->next;
     
	struct node* temp = head->next;
	
	rider->next->next = head->next->next;
	head->next = rider->next;
    rider->next = temp;
	temp->next = head;
}

int main()
{
	int n;
	
	struct node *head1 = NULL;
	struct node *head2 = NULL;
					
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *i = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the data: ");
	scanf("%d", &i->data);
	head->next = i;
	i->next = head;
	
	while(1)
	{
		printf("\n LIST OF OPERATIONS");
		printf("\n 1.Insertion at the front");
        printf("\n 2.Insertion at the end");
        printf("\n 3.Insertion in the middle");
        printf("\n 4.Insertion in sorted way");
        printf("\n 5.Deletion at the front");
        printf("\n 6.Deletion at the end");
        printf("\n 7.Deletion in the middle");
        printf("\n 8.Count");
        printf("\n 9.Split into two halves");
        printf("\n 10.Exchange first and last node");
        printf("\n 11.Exit");
        printf("\n Enter the choice:");
        scanf("%d", &n);
		switch(n)
		{
			case 1: addatbeg(head);
					display(head);
					break;
			case 2: addatend(head);
					display(head);
					break;
			case 3: addatmid(head);
					display(head);
					break;
			case 4: sorted_insert(head);
                    display(head);
                    break;
			case 5: delatbeg(head);
					display(head);
					break;
			case 6: delatend(head);
					display(head);
					break;
			case 7: delatmid(head);
					display(head);
					break;
			case 8: printf("No of nodes: %d", count(head));
					break;
			case 9: splitList(head, &head1, &head2);
					display(head1);
					printf("\n");
					display(head2);
					break;
			case 10: exchangeNodes(head);
					 display(head);
					 break;
			case 11: goto exit;
				
		}
	}
    exit:
    return 0;
}
