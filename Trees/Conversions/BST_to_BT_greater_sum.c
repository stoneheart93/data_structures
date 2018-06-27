#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BST_to_BTUtil(struct node* root, int* sum)
{
	if(root == NULL)
		return;
	
	BST_to_BTUtil(root->right, sum);
	
	*sum += root->data;
	root->data = *sum;
	//root->data = *sum - root->data; //excluding the current node's value
	
	BST_to_BTUtil(root->left, sum);	
}

void BST_to_BT(struct node* root) 
{
	if(root == NULL)
		return;
	
	int sum = 0;
	BST_to_BTUtil(root, &sum);
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
    struct node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13); 
    inorder(root);
	printf("\n");
	
	BST_to_BT(root);
    inorder(root);
 
	return 0;
}

