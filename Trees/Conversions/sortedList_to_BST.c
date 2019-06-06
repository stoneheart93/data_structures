
#include<stdio.h>
#include<stdlib.h>

struct Lnode
{
	int data;
	struct Lnode* next;
};

struct Tnode
{
	int data;
	struct Tnode* left;
	struct Tnode* right;
};

struct Lnode* newLNode(int data)
{
    struct Lnode *temp = (struct Lnode*)malloc(sizeof(struct Lnode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct Tnode* newTNode(int data)
{
    struct Tnode *temp = (struct Tnode*)malloc(sizeof(struct Tnode));
	temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int count(struct Lnode* head)
{
	int c = 0;
	while(head != NULL)
	{
		head = head->next;
		c++;
	}
	return c;
}

struct Tnode* sortedListToBSTUtil(struct Lnode** head, int n)
{
	if(n <= 0)
		return NULL;
	
	struct Tnode* left = sortedListToBSTUtil(head, n/2);
	
	struct Tnode* root = newTNode((*head)->data);
	(*head) = (*head)->next;
	
	struct Tnode* right = sortedListToBSTUtil(head, n - n/2 - 1);
	
	root->left = left;
	root->right = right;
	
	return root;
}

struct Tnode* sortedListToBST(struct Lnode* head)
{
	int n = count(head);
	sortedListToBSTUtil(&head, n);
}

void inorder(struct Tnode* root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int main()
{
	struct Lnode* head = NULL;
	head = newLNode(1);
	head->next = newLNode(2);
	head->next->next = newLNode(3);
	head->next->next->next = newLNode(4);
	head->next->next->next->next = newLNode(5);
	head->next->next->next->next->next = newLNode(6);
	head->next->next->next->next->next->next = newLNode(7);

	struct Tnode* root = sortedListToBST(head);
	
	inorder(root);
	
	return 0;
}

