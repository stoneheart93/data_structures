#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = key;
    node->left = NULL;
	node->right = NULL;
    return node;
}

struct node* lca(struct node* root, int k1, int k2)
{
	if(root == NULL)
		return NULL;
	
	if(root->data == k1 || root->data == k2)
		return root;
	
	struct node* left = lca(root->left, k1, k2);
	struct node* right = lca(root->right, k1, k2);
	
	if(left != NULL && right != NULL)
		return root;
	else if(left != NULL)
		return left;
	else
		return right;
}

int findLevel(struct node* root, int k, int level)
{
	if(root == NULL)
		return 0;
	if(root->data == k)
		return level;
	return findLevel(root->left, k, level + 1) | findLevel(root->right, k, level + 1); 
}

int shortestDistance(struct node* root, int k1, int k2)
{
	struct node* ancestor = lca(root, k1, k2);
	
	int d1 = findLevel(ancestor, k1, 0);
	int d2 = findLevel(ancestor, k2, 0);
	return d1 + d2 ;
}

int rootNodePath(struct node* root, int target)
{
	if(root == NULL)
		return 0;
	
	if(root->data == target)
		return 1;
		
	if(rootNodePath(root->left, target) || rootNodePath(root->right, target))
	{
		printf("%d ", root->data);
		return 1;
	}
	
	return 0;
}

void commonAncestors(struct node* root, int k1, int k2)
{
    struct node* LCA = lca(root, k1, k2);
    if(LCA == NULL)
    	return;
 
 	printf("%d ", LCA->data);
    rootNodePath(root, LCA->data);
}

void mirror(struct node* root) 
{
    if(root == NULL)
        return;
    
    mirror(root->left);
    mirror(root->right);
    
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
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
	int choice;
	int k1, k2, target;
	struct node* ancestor;
	
	/*  	1
		   / \
		  2   3
		/ \  / \
       4  5	6   7
            \
             8
	*/
	
	struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
	
	while(1)
	{
		printf("\nBinary Tree Operations:");
		printf("\n1.Lowest Common Ancestor");
		printf("\n2.Shortest Distance between two nodes");
		printf("\n3.Root to node path");
		printf("\n4.Ancestors of a node");
		printf("\n5.Common Ancestors of two nodes");
		printf("\n6.Convert to a mirror");
		printf("\n10.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: scanf("%d %d", &k1, &k2);
					ancestor = lca(root, k1, k2);
					printf("%d", ancestor->data);
				    break;
			case 2: scanf("%d %d", &k1, &k2);
				    printf("%d", shortestDistance(root, k1, k2));
				    break;
			case 3: scanf("%d", &target);
					if(!rootNodePath(root, target))
						printf("No Path");
					break;
			case 4: scanf("%d", &target);
				    rootNodePath(root, target);
				    break;
			case 5: scanf("%d %d", &k1, &k2);
					commonAncestors(root, k1, k2);
					break;
			case 6: mirror(root);
					inorder(root);
					break;
			case 10: goto exit;
		}
	}
	exit:
	return 0;
}
