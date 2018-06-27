#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int size(struct node* root)
{
	if(root == NULL)
		return 0;
	else
		return 1 + size(root->left) + size(root->right);
}

void storeInorder(struct node* root, int a[], int* index)
{
	if(root == NULL)
		return;
	
	storeInorder(root->left, a, index);
	a[(*index)] = root->data;
	(*index)++;
	storeInorder(root->right, a, index);
}

void arrayToMinHeap(int a[], struct node* root, int* index)
{
	if(root == NULL)
		return;
	
	root->data = a[(*index)];
	(*index)++;
	arrayToMinHeap(a, root->left, index);
	arrayToMinHeap(a, root->right, index);
}

void BSTToMinHeap(struct node* root)
{
	if(root == NULL)
		return;
			
	int n = size(root);
	
	int* a = (int*)malloc(sizeof(int)*n);
	int i = 0;
	storeInorder(root, a, &i);
	
	i = 0;
	arrayToMinHeap(a, root, &i);
	
	free(a);
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
	struct node *root = NULL;
 	root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
	inorder(root);
	printf("\n");
	
	BSTToMinHeap(root);
    inorder(root);
 
    return 0;
}
