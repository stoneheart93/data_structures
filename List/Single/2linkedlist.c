#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

};

void create(struct node **head)
{
    int flag;
    struct node *temp = (struct node *) malloc(sizeof(struct node)); 
    *head = temp; 
    do 
    {
        printf("\n Enter data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        printf("\n Continue adding more terms to the list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
        if(flag)
        {
            temp->next = (struct node*)malloc(sizeof(struct node));
            temp = temp->next;
            temp->next = NULL;
        }
    }while(flag);
}

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void display(struct node* head)
{
 	while(head != NULL)
	{
	    printf("-->%d", head->data);
	    head = head->next;
    }     
}

// O(n) since traversal of both entire lists
int identical(struct node *a, struct node *b)
{
    if(a == NULL && b == NULL)
    	return 1;
    else if(a != NULL && b != NULL)
    	return (a->data == b->data) && identical(a->next, b->next);
    else
    	return 0;
}   

// O(m + n) since traversal of both entire lists
struct node *mergeSortedLists(struct node *a, struct node *b) 
{
    if(a == NULL) 
        return b;
    
	if(b == NULL) 
        return a;
       
	if(a->data <= b->data) 
    {
    	a->next = mergeSortedLists(a->next, b);
    	return a;
    }
    else
    {
        b->next = mergeSortedLists(a, b->next);
        return b;
    }
} 

// O(m + n) since traversal of both entire lists
struct node *intersectSortedLists(struct node *a, struct node *b)
{
    if(a == NULL || b == NULL)
    	return NULL;
 
    if(a->data < b->data)
    	return intersectSortedLists(a->next, b);
    else if(a->data > b->data)
        return intersectSortedLists(a, b->next);
 	else
 	{
		struct node *result = newNode(a->data);
		result->next = intersectSortedLists(a->next, b->next);
    	return result;
    }
}

int getIntesectionNodeUtil(int d, struct node* a, struct node* b)
{
    int i;
    for(i = 0; i < d; i++)
        a = a->next;
    while(a != NULL && b != NULL)
    {
        if(a->data == b->data)
            return a->data;
        a = a->next;
        b = b->next;
    }
    return -1;
} 
int count(struct node *head)
{
	int count=0;
    while(head != NULL)
	{
	    count++;
        head = head->next;
    } 
    return count;    
} 
int getIntesectionNode(struct node *a, struct node *b)
{
    int c1 = count(a);
    int c2 = count(b);
    int d;
    if(c1 > c2)
    {
        d = c1-c2;
        return getIntesectionNodeUtil(d, a, b);
    }
    else
    {
        d = c2 - c1;
        return getIntesectionNodeUtil(d, b, a);
    }
}

int main()
{
    int choice;
    struct node *head1, *head2;
	struct node *res,*res1;
	printf("\n\n List1");
    create(&head1);
    display(head1);
    
	printf("\n\n List2");
    create(&head2);
    display(head2);
    
	while(1)
    {
    	printf("\n\n LIST OPERATIONS");
        printf("\n 1.Identical");
        printf("\n 2.Merge two sorted lists");
        printf("\n 3.Intersect two sorted lists");
        printf("\n 4.Intersection node");
        printf("\n 5.Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
        	case 1: if(identical(head1, head2))
                        printf("\n The two lists are identical");
                    else
                        printf("\n The two lists are not identical");
                    break;
        	case 2: res = mergeSortedLists(head1, head2);
                    display(res);
                    break;
            case 3: res = intersectSortedLists(head1, head2);
            		display(res);
            		break;
            case 4: printf("\n The node of intersection is %d \n", getIntesectionNode(head1, head2)); 
                    break;
            case 5: goto exit;
    	}
    }
    exit:
    return 0;
}   
