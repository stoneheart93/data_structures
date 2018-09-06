// O(n) and O(1) space
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next, *random;
};
 
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
    while(rider != NULL)
    {
        printf("Data = %d, Random = %d\n", rider->data, rider->random->data);
        rider = rider->next;
    }
}
struct node* clone(struct node *org_start)
{
    struct node *rider = org_start;
	struct node *temp;
    while(rider != NULL)
    {
        temp = rider->next;
        rider->next = newNode(rider->data);
        rider->next->next = temp;
        rider = temp;
    }
 
    rider = org_start;
    while(rider != NULL)
    {
        rider->next->random = rider->random->next;
        rider = rider->next? rider->next->next : rider->next;
    }
 
    struct node *original = org_start;
	struct node *copy = org_start->next;
 
    struct node *copy_start = copy;
 
    while(original && copy)
    {
        original->next = original->next? original->next->next : original->next;
        copy->next = copy->next? copy->next->next: copy->next;
        original = original->next;
        copy = copy->next;
    }
	return copy_start;
}
 
int main()
{
    struct node *start = newNode(1);
    start->next = newNode(2);
    start->next->next = newNode(3);
    start->next->next->next = newNode(4);
    start->next->next->next->next = newNode(5);
 
    // 1's random points to 3
    start->random = start->next->next;
 
    // 2's random points to 1
    start->next->random = start;
 
    // 3's and 4's random points to 5
    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;
 
    // 5's random points to 2
    start->next->next->next->next->random = start->next;
 
    printf("Original list:\n");
	display(start);
 
    printf("Cloned list:\n");
	struct node *cloned_list = clone(start);
    display(cloned_list);
 
    return 0;
}
