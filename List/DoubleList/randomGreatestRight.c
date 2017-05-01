#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next, *random;
}*start;
 
struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->random = NULL;
	return temp;
}
 
void display(struct node *rider)
{
    while(rider->next != NULL)
    {
        printf("Data = %d, Random = %d\n", rider->data, rider->random->data);
        rider = rider->next;
    }
}

void reverse(struct node* rider)
{
    struct node* prev = NULL;
    struct node* temp;
    while(rider != NULL)
    {
        temp = rider->next;
        rider->next = prev;
        prev = rider;
    	rider = temp;
   	}
    start = prev;
}

void populateRandom()
{
    reverse(start);
	
	struct node *max = start;
    struct node *rider = start->next;
    while(rider != NULL)
    {
        rider->random = max;
        if(rider->data > max->data)
            max = rider;
		rider = rider->next; 
    }
 	
	reverse(start);
}
 
int main()
{
    start = newNode(5);
    start->next = newNode(10);
    start->next->next = newNode(2);
    start->next->next->next = newNode(3);
    
	populateRandom();
    display(start);
 
    return 0;
}
