#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void BTtoDLL(struct node* root, struct node** head)
{
	if(root == NULL)
		return;
		
	BTtoDLL(root->right, head);
	
	root->right = *head;
	if((*head) != NULL)
		(*head)->left = root;
	*head = root;
		
	BTtoDLL(root->left, head);
}

void display(struct node* head)
{
	struct node* rider = head;
	while(rider != NULL)
	{
		printf("%d-->", rider->data);
		rider = rider->right;
	}
}

struct node* newTNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
	struct node* root = newTNode(5); 
    root->left = newTNode(3); 
    root->right = newTNode(6); 
    root->left->left = newTNode(1); 
    root->left->right = newTNode(4); 
    root->right->right = newTNode(8); 
    root->left->left->left = newTNode(0); 
    root->left->left->right = newTNode(2); 
    root->right->right->left = newTNode(7); 
    root->right->right->right = newTNode(9); 
  
    struct node* head = NULL; 
    BTtoDLL(root, &head); 
  
    display(head); 
    
    return 0;
}
