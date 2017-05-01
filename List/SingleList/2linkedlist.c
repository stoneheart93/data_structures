#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

};

void create(struct node **start)
{
    int flag;
    struct node *temp=(struct node *) malloc(sizeof(struct node)); 
    *start=temp; 
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

void display(struct node* rider)
{
 	while(rider != NULL)
	{
	    printf("-->%d", rider->data);
	    rider = rider->next;
    }     
}

int identical(struct node *a, struct node *b)
{
    while(1)
    {
    	if(a == NULL && b == NULL)
            return 1;
        if(a == NULL && b != NULL)
            return 0; 
        if(a != NULL && b == NULL)
            return 0; 
        if(a->data != b->data)
            return 0; 
        a = a->next;
        b = b->next; 
    }          
}   

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
 
int count(struct node *rider)
{
	int count=0;
    while(rider!=NULL)
	{
	    count++;
        rider=rider->next;
    } 
    return count;    
} 
int getIntesectionNode(struct node *start1, struct node *start2)
{
    int c1 = count(start1);
    int c2 = count(start2);
    int d;
    if(c1 > c2)
    {
        d = c1-c2;
        return getIntesectionNodeUtil(d, start1, start2);
    }
    else
    {
        d = c2 - c1;
        return getIntesectionNodeUtil(d, start2, start1);
    }
}
int getIntesectionNodeUtil(int d, struct node* a, struct node* b)
{
    int i;
    for(i = 0; i < d; i++)
    {
        if(a == NULL)
        	return -1; 
        a = a->next;
    }
    while(a != NULL && b != NULL)
    {
        if(a->data == b->data)
            return a->data;
        a = a->next;
        b = b->next;
    }
    return -1;
}

int main()
{
    int choice;
    struct node *start1, *start2;
	struct node *res,*res1;
	printf("\n\n List1");
    create(&start1);
    display(start1);
    
	printf("\n\n List2");
    create(&start2);
    display(start2);
    
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
        	case 1: if(identical(start1, start2))
                        printf("\n The two lists are identical");
                    else
                        printf("\n The two lists are not identical");
                    break;
        	case 2: res = mergeSortedLists(start1, start2);
                    display(res);
                    break;
            case 3: res = intersectSortedLists(start1, start2);
            		display(res);
            		break;
            case 4: printf("\n The node of intersection is %d \n", getIntesectionNode(start1, start2)); 
                    break;
            case 5: goto exit;
    	}
    }
    exit:
    return 0;
}   
