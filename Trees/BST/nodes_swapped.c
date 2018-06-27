
#include<stdio.h>
#include<stdlib.h>


struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void recoverBSTUtil(struct node* root, struct node** prev, struct node** first, struct node** last)
{
	if(root == NULL)
		return;
	
	recoverBSTUtil(root->left, prev, first, last);
	
	if((*prev) != NULL)
	{
		if((*prev)->data > root->data)
		{
			if((*first) == NULL)
			{
				*first = *prev;	
			}
			*last = root;
		}		
	}
	*prev = root;
	
	recoverBSTUtil(root->right, prev, first, last);
}

void recoverBST(struct node* root) 
{
	if(root == NULL)
		return;
		
	struct node* prev = NULL, *first = NULL, *last = NULL;
	recoverBSTUtil(root, &prev, &first, &last);
	swap(&first->data, &last->data);
} 

struct node* newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}
 
int main()
{
    struct node *root = newNode(6);
    root->left = newNode(10);
    root->right = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7); 
    inorder(root);
	printf("\n");
	
	recoverBST(root);
    inorder(root);
 
    
	return 0;
}
