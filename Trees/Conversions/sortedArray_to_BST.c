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

struct node* sortedArrayToBST(int a[], int start, int end)
{
	if(start > end)
		return NULL;
		
	int mid = (start + end)/2;
	struct node* root = newNode(a[mid]);
	
	root->left = sortedArrayToBST(a, start, mid-1);
	root->right = sortedArrayToBST(a, mid+1, end);
	
	return root;
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
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	struct node* root = sortedArrayToBST(a, 0, n-1);
	inorder(root);
	return 0;
}
