#include<iostream>
#include<queue>
using namespace std;

struct node
{
    struct node *left;
    int no;
    struct node *right;
}*root;

int heightIter(struct node* root) 
{
	int height = 0;
	queue<node*> q;
	q.push(root);
	
	while(1)
	{
		int no_of_nodes = q.size();
		if(no_of_nodes == 0)
			return height;
		
		height++;
		
		while(no_of_nodes > 0)
		{
			struct node* temp =q.front();
			q.pop();
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			no_of_nodes--;
		}
	}
}

struct node* newNode(int data)
{
    struct node *temp = new node;
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
 	
	printf("%d", heightIter(root));
    return 0;
}
