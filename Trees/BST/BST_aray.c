#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	struct node* left;
	struct node* right;
	int data;
};


struct node* newNode(int key)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
struct node* constructUtil(int pre[], int *index, int n, int key, int min, int max)
{
	if(*index >= n)	
		return NULL;
	struct node* root = NULL;

	if(key >= min && key <= max)
	{
		root = newNode(key);		
		*index = *index + 1;
	
		root->left = constructUtil(pre, index, n, pre[*index], min, key-1);
		
		root->right = constructUtil(pre, index, n, pre[*index], key+1, max);
	}
	return root;
}
struct node* construct(int pre[], int n)
{
	int index = 0;
	return constructUtil(pre, &index, n, pre[0], INT_MIN, INT_MAX);
}

void inorder(struct node* root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int max(int a, int b)
{
	return (a > b)? a: b;
}
int min(int a, int b)
{
	return (a < b)?a : b;
}
int hasOneChild(int pre[], int n)
{
	int i;
	for(i = 0; i < n - 1; i++)
	{
		int nextDiff = pre[i] - pre[i + 1];
		int lastDiff = pre[i] - pre[n - 1];
		if(nextDiff * lastDiff < 0)
			return 0;
	}
	return 1;
}

int main()
{
	int traversal, n, i, choice;
	int a[200];
	struct node* root;
	
	printf("\n1-Preorder;2-Inorder;3-Postorder\n");
	scanf("%d", &traversal);
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	if(traversal == 1)
	{
		while(1)
		{
			printf("\n1.Construct Tree");
			printf("\n2.Check if it has only one child");
			printf("\n3.Exit\n");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1: root = construct(a, n);
						inorder(root);
						break;
				case 2: if(hasOneChild(a, n))
							printf("Only One Child");
						else
							printf("No");
						break;
				case 3: goto exit;
			}
		}
	}
	exit:
		return 0;
}

