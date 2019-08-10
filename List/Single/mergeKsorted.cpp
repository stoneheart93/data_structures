#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node *next;

};

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

struct compare { 
    bool operator()(struct node* a, struct node* b) 
    { 
        return a->data > b->data; 
    } 
}; 

struct node* mergeKSortedLists(struct node* a[], int k)
{
	priority_queue<struct node*, vector<struct node*>, compare > min_heap;
	
	for(int i = 0; i < k; i++)
		min_heap.push(a[i]);
	
	struct node* head = NULL;
	struct node* last = NULL;
	
	while(!min_heap.empty())
	{
		struct node* temp = min_heap.top();
		min_heap.pop();
		
		if(head == NULL)
		{
			head = temp;
			last = temp;
		}
		else
		{
			last->next = temp;
			last = temp;
		}
		
		if(temp->next != NULL)
			min_heap.push(temp->next);
	}	
	return head;
}

int main() 
{ 
    int k = 3; // Number of linked lists 
    struct node* a[k]; 
  
    a[0] = newNode(1); 
    a[0]->next = newNode(3); 
    a[0]->next->next = newNode(5); 
    a[0]->next->next->next = newNode(7); 
  
    a[1] = newNode(2); 
    a[1]->next = newNode(4); 
    a[1]->next->next = newNode(6); 
    a[1]->next->next->next = newNode(8); 
  
    a[2] = newNode(0); 
    a[2]->next = newNode(9); 
    a[2]->next->next = newNode(10); 
    a[2]->next->next->next = newNode(11); 
  
    struct node* head = mergeKSortedLists(a, k); 
  	display(head); 
  
    return 0; 
} 

