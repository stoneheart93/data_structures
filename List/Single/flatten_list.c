#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* right;
	struct node* down;

};

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->down = NULL;
	temp->right = NULL;
	return temp;
}

void display(struct node* head)
{
 	while(head != NULL)
	{
	    printf("-->%d", head->data);
	    head = head->down;
    }     
}

struct node* mergeSortedLists(struct node* a, struct node* b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
		
	if(a->data <= b->data)
	{
		a->down = mergeSortedLists(a->down, b);
		return a;
	}
	else
	{
		b->down = mergeSortedLists(a, b->down);
		return b;
	}
}


struct node* flatten(struct node* head)
{
	if(head == NULL || head->right == NULL)
		return head;

	return mergeSortedLists(head, flatten(head->right));
}
		
int main() 
{ 
    struct node* head; 
  
    head = newNode(5); 
    head->down = newNode(7); 
    head->down->down = newNode(8); 
    head->down->down->down = newNode(30); 
  
    head->right = newNode(10); 
    head->right->down = newNode(20); 
    
	head->right->right = newNode(19);
	head->right->right->down = newNode(22);
	head->right->right->down->down = newNode(50);
	 
    head->right->right->right = newNode(35);
	head->right->right->right->down = newNode(40);
	head->right->right->right->down->down = newNode(45);
	
    head = flatten(head); 
  	display(head); 
  
    return 0; 
} 


