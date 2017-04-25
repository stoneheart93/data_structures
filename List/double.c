#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	struct node *lptr;
	int data;
	struct node *rptr;
}*start;

void addatbeg()
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the value to be inserted at the begining: ");
	scanf("%d", &temp->data);
	temp->lptr = NULL;
	temp->rptr = start;
	start->lptr = temp;
	start = temp;
}

void addatend(struct node *rider)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the value to be inserted at the end: ");
	scanf("%d", &temp->data);
	while(rider->rptr != NULL)
		rider = rider->rptr;
	temp->lptr = rider;
	temp->rptr = NULL;
	rider->rptr = temp;
}

void addatmid(struct node *rider)
{
	int num;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the value to be inserted at the middle: ");
	scanf("%d", &temp->data);
	printf("\n Enter the value before the number is to be inserted: ");
	scanf("%d", &num);
	while(rider->rptr!=NULL && rider->rptr->data!=num)
		rider = rider->rptr;
	temp->lptr = rider;
	temp->rptr = rider->rptr;
	rider->rptr->lptr = temp;
	rider->rptr = temp;
	
}

void delatbeg()
{
	struct node *temp = start;
	start->rptr->lptr = NULL;
	start = start->rptr;
	free(temp);
}

void delatend(struct node *rider)
{
    while(rider->rptr->rptr != NULL)
		rider = rider->rptr;
	struct node *temp = rider->rptr;
	rider->rptr = NULL;
	free(temp);
}

void delatmid(struct node *rider)
{
	int  num;
	printf("\n Enter the value to be deleted: ");
	scanf("%d", &num);
	while(rider->rptr->data != num)
		rider = rider->rptr;
	struct node *temp = rider->rptr;
	rider->rptr = temp->rptr;
	temp->rptr->lptr = rider;
	temp->lptr = NULL;
	free(temp);

}

void display(struct node *rider)
{
	while(rider != NULL)
	{
		printf("---->%d", rider->data);
		rider = rider->rptr;
	}
}

void reverse(struct node *rider)
{
    struct node *temp = NULL;  
    while(rider != NULL)
    {
        temp = rider->lptr;
        rider->lptr = rider->rptr;
        rider->rptr = temp;              
        rider = rider->lptr;
    }      
    if(temp != NULL)
    	start = temp->lptr;
}     
 
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
struct node* partition(struct node *low, struct node *high)
{
	int pivot = high->data;
	struct node *i = low->lptr;
 
	struct node *j;
	for(j = low; j != high; j = j->rptr)
    {
        if(j->data <= pivot)
        {
            i = (i == NULL)? low : i->rptr;
			swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? low : i->rptr; 
    swap(&(i->data), &(high->data));
    return i;
} 
void quick_sortUtil(struct node *low, struct node *high)
{
    if(high != NULL && low != high && low != high->rptr)
    {
        struct node *p = partition(low, high);
        quick_sortUtil(low, p->lptr);
        quick_sortUtil(p->rptr, high);
    }
}
void quick_sort()
{
	struct node *high = start;
	while(high->rptr != NULL)
		high = high->rptr;
    quick_sortUtil(start, high);
}

struct node *merge(struct node *first, struct node *second)
{
    if(!first)
    	return second;
 
    if(!second)
    	return first;
 
    if(first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
 
// Function to do merge sort
struct node *mergeSort(struct node *head)
{
    if (!head || !head->next)
        return head;
    struct node *second = split(head);
 
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
 
    // Merge the two sorted halves
    return merge(head,second);
}

int main()
{
    int n;
	
	struct node *i = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter the value of the data: ");
	scanf("%d", &i->data);
	i->lptr = NULL;
	i->rptr = NULL;
	start = i;
	
	while(1)
	{
        printf("\n LIST OF OPERATIONS");
		printf("\n 1.Insertion at the front");
        printf("\n 2.Insertion at the end");
        printf("\n 3.Insertion in the middle");
        printf("\n 4.Deletion at the front");
        printf("\n 5.Deletion at the end");
        printf("\n 6.Deletion in the middle");
        printf("\n 7.Reverse");
        printf("\n 8.Quick sort");
        printf("\n 9.Exit");
        printf("\n Enter the choice:");
        scanf("%d", &n);
		switch(n)
		{
			case 1: addatbeg();
					display(start);
					break;
			case 2: addatend(start);
					display(start);
					break;
			case 3:	addatmid(start);
					display(start);
					break;
			case 4:	delatbeg();
					display(start);
					break;
			case 5:	delatend(start);
					display(start);
					break;
			case 6:	delatmid(start);
					display(start);
					break;
			case 7: reverse(start);
			        display(start);
			        break;
			case 8: quick_sort(start);
					display(start);
					break;
            case 9: goto exit;
		}
	}
    exit:
    return 0;
}
