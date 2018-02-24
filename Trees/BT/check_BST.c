#include<stdio.h>
#include<limits.h>

struct node
{
    struct node *left;
    int no;
    struct node *right;
}*root;

int isBST(struct node* root, int min, int max) 
{ 
	if(root == NULL) 
    	return 1;
       
	if(root->no < min || root->no > max) 
    	return 0; 
 
	return isBST(root->left, min, root->no - 1) && isBST(root->right, root->no + 1, max); 
} 

struct node* newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->no = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 	
	printf("\n%d", isBST(root, INT_MIN, INT_MAX));
	
	root = newNode(4);
	root->left        = newNode(2);
	root->right       = newNode(5);
	root->left->left  = newNode(1);
	root->left->right = newNode(3);
	
    printf("\n%d", isBST(root, INT_MIN, INT_MAX));
	
	return 0;
}
