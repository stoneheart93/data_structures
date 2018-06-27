#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

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

void arrayToBST(int a[], struct node* root, int* index)
{
	if(root == NULL)
		return;
	
	arrayToBST(a, root->left, index);
	root->data = a[(*index)];
	(*index)++;
	arrayToBST(a, root->right, index);
}

void BTToBST(struct node* root)
{
	if(root == NULL)
		return;
			
	int n = size(root);
	
	int *a = new int[n];
	int i = 0;
	storeInorder(root, a, &i);
	
	sort(a, a+n);
	
	i = 0;
	arrayToBST(a, root, &i);
	
	delete[] a;
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
 	root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    inorder(root);
	printf("\n");
	BTToBST(root);
    inorder(root);
 
    return 0;
}

