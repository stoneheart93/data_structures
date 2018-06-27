#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(struct node* root, int key)
{
	if(root == NULL)
	{
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = key;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	
	if(key < root->data)
		root->left = insert(root->left, key);
	else if(key > root->data)
		root->right = insert(root->right, key);
		
	return root;
}

int identical(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return 1;
	else if(a != NULL && b != NULL)
		return (a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right));
	else
		return 0;
}


int main()
{
	struct node* root1 = NULL;
	struct node* root2 = NULL;
	
	int key, flag, choice;
	
	printf("\nTree1\n");
	while(1)
	{
		scanf("%d", &key);
		root1 = insert(root1, key);
		printf("Do you wish to insert? ");
		scanf("%d", &flag);
		if(flag == 0)
			break;
	}
	
	printf("\nTree2\n");
	while(1)
	{
		scanf("%d", &key);
		root2 = insert(root2, key);
		printf("Do you wish to insert? ");
		scanf("%d", &flag);
		if(flag == 0)
			break;
	}
	
	while(1)
	{
		printf("\nOperations:");
		printf("\n1.Identical");
		printf("\n10.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: if(identical(root1, root2))
						printf("Identical");
					else
						printf("Not identical");
			case 10: goto exit;
		}
	}
	exit:
		return 0;
}
	

