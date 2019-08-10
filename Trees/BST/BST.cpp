#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<unordered_set>
#include<set>
#include<iostream>
using namespace std;

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

int searchRec(struct node* root, int key)
{
	if(root == NULL)
		return 0;
	
	if(key == root->data)
		return 1;
	else if(key < root->data)
		return searchRec(root->left, key);
	else
		return searchRec(root->right, key);
}

int searchIter(struct node* root, int key)
{
	while(root != NULL)
	{
		if(key == root->data)
			return 1;
		else if(key < root->data)
			root = root->left;
		else
			root = root->right;
	}
	return 0;
}

struct node* findmin(struct node* root)
{
	while(root->left != NULL)
		root = root->left;
	return root;
}

struct node* findmax(struct node* root)
{
	while(root->right != NULL)
		root = root->right;
	return root;
}

struct node* deleteNode(struct node* root, int key)
{
	if(root == NULL)
		return NULL;
	
	if(key == root->data)
	{
		if(root->left == NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		else if(root->left != NULL && root->right != NULL)
		{
			struct node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	if(key < root->data)
		root->left = deleteNode(root->left, key);
	else
		root->right = deleteNode(root->right, key);
	
	return root;
}

struct node* deleteLeaf(struct node* root)
{
	if(root == NULL)
		return NULL;
	
	if(root->left == NULL && root->right == NULL)
	{
		free(root);
		return NULL;
	}
	root->left = deleteLeaf(root->left);
	root->right = deleteLeaf(root->right);
	
	return root;
}

struct node* deleteLeafWithK(struct node* root, int k)
{
	if(root == NULL)
		return NULL;
	
	if(root->left == NULL && root->right == NULL && root->data == k)
	{
		free(root);
		return NULL;
	}
	root->left = deleteLeafWithK(root->left, k);
	root->right = deleteLeafWithK(root->right, k);
	
	return root;
}

struct node* deleteTree(struct node* root)
{
	if(root == NULL)
		return NULL;
		
	root->left = deleteTree(root->left);
	root->right = deleteTree(root->right);
	
	free(root);
	return NULL;
}

void FloorCeilRec(struct node* root, struct node** floor, struct node** ceil, int key)
{
	if(root == NULL)
		return;
		
	if(key == root->data)
	{
		*floor = root;
		*ceil = root;
	}
	else if(key < root->data)
	{
		*ceil = root;
		FloorCeilRec(root->left, floor, ceil, key);
	}
	else
	{
		*floor = root;
		FloorCeilRec(root->right, floor, ceil, key);
	}
}

void FloorCeilIter(struct node* root, struct node** floor, struct node** ceil, int key)
{
	while(root != NULL)
	{
		if(key == root->data)
		{
			*floor = root;
			*ceil = root;
		}
		else if(key < root->data)
		{
			*ceil = root;
			root = root->left;
		}
		else
		{
			*floor = root;
			root = root->right;
		}
	}
}

int sizeRec(struct node* root)
{
	if(root == NULL)
		return 0;

	return 1 + sizeRec(root->left) + sizeRec(root->right);
}

int sizeIter(struct node* root)
{
    if(root == NULL)
    	return 0;
 
	int size = 1;
	queue<struct node*> q;
	q.push(root);
		
	while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
 
        if(temp->left != NULL)
        {
            q.push(temp->left);
        	size++;
        }
		if(temp->right != NULL)
        {
        	q.push(temp->right);
        	size++;
        }
    }
    return size;
}


int max(int a, int b)
{
	return (a > b)? a: b;
}
int heightRec(struct node* root) 
{
    if(root == NULL) 
        return 0;

    return 1 + max(heightRec(root->left), heightRec(root->right));
} 

int heightIter(struct node* root)
{
	if(root == NULL)
		return 0;
	
	int height = 0;
	queue<struct node*> q;
	q.push(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			return height;
		
		height++;
		
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
}


int isBalanced(struct node* root)
{
	if(root == NULL)
		return 1;
	
	int lh = heightRec(root->left);
	int rh = heightRec(root->right);
	
	if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;
	else
		return 0;
}

int leafCountRec(struct node* root)
{
    if(root == NULL)       
        return 0;
	
	if(root->left == NULL && root->right == NULL)      
        return 1;            
    return leafCountRec(root->left) + leafCountRec(root->right);      
}    

int leafCountIter(struct node* root)
{
    if(root == NULL)
    	return 0;
 
	int count = 0;
	queue<struct node*> q;
	q.push(root);
		
	while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
 
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
        if(temp->left == NULL && temp->right == NULL)
            count++;
    }
    return count;
}

int nonleafCount(struct node* root)
{
    if(root == NULL)       
        return 0;
	
	if(root->left == NULL && root->right == NULL)      
        return 0;            
    return 1 + nonleafCount(root->left) + nonleafCount(root->right);      
}    

int fullnodeCount(struct node* root)
{
	if(root == NULL)
		return 0;
	
	if(root->left != NULL && root->right != NULL)
		return 1 + fullnodeCount(root->left) + fullnodeCount(root->right);
	return fullnodeCount(root->left) + fullnodeCount(root->right);
}

int halfnodeCount(struct node* root)
{
	if(root == NULL)
		return 0;
	
	if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
		return 1 + halfnodeCount(root->left) + halfnodeCount(root->right);
	return halfnodeCount(root->left) + halfnodeCount(root->right);
}

int sumNodes(struct node* root)
{
	if(root == NULL)
		return 0;

	return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int isLeaf(struct node* root)
{
	if(root == NULL)
		return 0;
		
	if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return 0;
}
int sumLeftLeafNodes(struct node* root)
{
	if(root == NULL)
		return 0;
		
	return (isLeaf(root->left) ? root->left->data : 0) + sumLeftLeafNodes(root->left) + sumLeftLeafNodes(root->right);
}

int sumRightLeafNodes(struct node* root)
{
	if(root == NULL)
		return 0;
		
	return (isLeaf(root->right) ? root->right->data : 0) + sumRightLeafNodes(root->left) + sumRightLeafNodes(root->right);
}

int sumLeafNodes(struct node* root)
{
	if(root == NULL)
		return 0;
		
	if(root->left == NULL && root->right == NULL)
		return root->data;
	return sumLeafNodes(root->left) + sumLeafNodes(root->right);
}

void inorder(struct node* root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void preorder(struct node* root)
{
	if(root == NULL)
		return;
	
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node* root)
{
	if(root == NULL)
		return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

/*
1. To return to the root node, we can create a link from some node (let’s cal it pre) in its left sub tree 
to it. Further more, to avoid breaking the tree structure, we can utilize the x nodes whose left (or right) 
child is NULL (i.e. if x->left == NULL (or x->right == NULL) we can link it to the root: 
x->left = root (or x->right = root).
2. It would be natural if we choose the node pre so that it comes right before its root node in inorder tree 
traversal (let’s call pre is predecessor node of its root node).
*/
void morris(struct node* root)
{
	if(root == NULL)
		return;
	
	struct node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			printf("%d ", current->data);
			current = current->right;
		}
		else
		{
			struct node* pre = current->left;
			while(pre->right != NULL && pre->right!= current)
				pre = pre->right;
			
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				printf("%d ", current->data);
				current = current->right;
			}
		}
	}
}

void iterativePreorder(struct node* root)
{
	if(root == NULL)
		return;
	
	stack<struct node*> s;
	s.push(root);
	
	while(!s.empty())
	{
		struct node* temp = s.top();
		s.pop();
		
		printf("%d ", temp->data);
		
		if(temp->right != NULL)
			s.push(temp->right);
		if(temp->left != NULL)
			s.push(temp->left);
	}
}

void iterativePostorder(struct node* root)
{
	if(root == NULL)
		return;
		
	stack<struct node*> child, parent;
	child.push(root);
	
	while(!child.empty())
	{
		struct node* temp = child.top();
		child.pop();
		parent.push(temp);
		
		if(temp->left != NULL)
			child.push(temp->left);
		if(temp->right != NULL)
			child.push(temp->right);
	}
	
	while(!parent.empty())
	{
		struct node* temp = parent.top();
		parent.pop();
		printf("%d", temp->data);
	}
}

void reverseMorris(struct node* root)
{
	if(root == NULL)
		return;
	
	struct node* current = root;
	while(current != NULL)
	{
		if(current->right == NULL)
		{
			printf("%d ", current->data);
			current = current->left;
		}
		else
		{
			struct node* pre = current->right;
			while(pre->left != NULL && pre->left != current)
				pre = pre->left;
			
			if(pre->left == NULL)
			{
				pre->left = current;
				current = current->right;
			}
			else
			{
				pre->left = NULL;
				printf("%d ", current->data);
				current = current->left;
			}
		}
	}
}

void levelOrder(struct node* root)
{
	if(root == NULL)
		return;
	
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		struct node* temp = q.front();
		q.pop();
		
		printf("%d ", temp->data);
		
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
}

void levelOrder1by1(struct node* root)
{
	if(root == NULL)
		return;
	
	queue<struct node*> q;
	q.push(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			break;
		
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			printf("%d ", temp->data);
			
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		printf("\n");
	}
}

void levelOrderSpiral(struct node* root)
{
	if(root == NULL)
		return;
		
	int leftToright = 0;
		
	deque<struct node*> q;
	q.push_back(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			break;
		
		for(int i = 1; i <= n; i++)
		{
			if(leftToright)
			{
				struct node* temp = q.front();
				q.pop_front();
				
				printf("%d ", temp->data);
				
				if(temp->left != NULL)
					q.push_back(temp->left);
				if(temp->right != NULL)
					q.push_back(temp->right);		
			}
			else
			{
				struct node* temp = q.back(); 
				q.pop_back();
				
				printf("%d ", temp->data);
				
				if(temp->right != NULL)
					q.push_front(temp->right);		
				if(temp->left != NULL)
					q.push_front(temp->left);
			}
		}
		printf("\n");
		leftToright = !leftToright;
	}
}

void levelOrderDirectionChange(struct node* root)
{
	if(root == NULL)
		return;
		
	int leftToright = 0;
	int count = 0;
	
	deque<struct node*> q;
	q.push_back(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			break;
		
		count++;
		for(int i = 1; i <= n; i++)
		{
			if(leftToright)
			{
				struct node* temp = q.front();
				q.pop_front();
				
				printf("%d ", temp->data);
				
				if(temp->left != NULL)
					q.push_back(temp->left);
				if(temp->right != NULL)
					q.push_back(temp->right);		
			}
			else
			{
				struct node* temp = q.back(); 
				q.pop_back();
				
				printf("%d ", temp->data);
				
				if(temp->right != NULL)
					q.push_front(temp->right);		
				if(temp->left != NULL)
					q.push_front(temp->left);
			}
		}
		printf("\n");
		if(count == 2)
		{
			leftToright = !leftToright;
			count = 0;
		}
	}
}

void reverseLevelOrder(struct node* root)
{
	if(root == NULL)
		return;
	
	queue<struct node*> q;
	q.push(root);
	
	stack<struct node*> s;
	
	while(!q.empty())
	{
		struct node* temp = q.front();
		q.pop();
		
		s.push(temp);
		
		if(temp->right != NULL)
			q.push(temp->right);
		if(temp->left != NULL)
			q.push(temp->left);
	}
	
	while(!s.empty())
	{
		struct node* temp = s.top();
	   	s.pop();
		printf("%d ", temp->data);
	}
}

void verticalOrder(struct node* root)
{
	if(root == NULL)
		return;
	
	int hd = 0;
	map<int, vector<int>> m;
	
	queue<pair<struct node*, int>> q;
	q.push(make_pair(root, hd));
	
	while(!q.empty())
	{
		pair<struct node*, int> temp_pair = q.front();
		q.pop();
		
		struct node* temp = temp_pair.first;
		hd = temp_pair.second;
		
		m[hd].push_back(temp->data);
		
		if(temp->left != NULL)
			q.push(make_pair(temp->left, hd-1));
		if(temp->right != NULL)
			q.push(make_pair(temp->right, hd+1));
		
	}
	
	for(map<int, vector<int> >::iterator it = m.begin(); it!= m.end(); it++)
	{
		for(int i = 0; i < it->second.size(); i++)
			printf("%d ", it->second[i]);
		printf("\n");
	}
}

void printBoundaryLeft(struct node* root)
{
	if(root == NULL)
		return;
	
	if(root->left != NULL)
	{
		printf("%d ", root->data);
		printBoundaryLeft(root->left);
	}
	else if(root->right != NULL)
	{
		printf("%d ", root->data);
		printBoundaryLeft(root->right);
	}
}

void printLeaves(struct node* root)
{
	if(root == NULL)
		return;
	
	if(root->left == NULL && root->right == NULL)
		printf("%d ",root->data);
	printLeaves(root->left);
	printLeaves(root->right);
}

void printBoundaryRight(struct node* root)
{
	if(root == NULL)
		return;
	
	if(root->right != NULL)
	{
		printBoundaryRight(root->right);
		printf("%d ", root->data);
	}
	else if(root->left != NULL)
	{
		printBoundaryRight(root->left);
		printf("%d ", root->data);
	}
}

void boundary(struct node* root)
{
	if(root == NULL)
		return;

	printBoundaryLeft(root);
	printLeaves(root);
	printBoundaryRight(root);
}

void nInorder(struct node* root, int n)
{
	if(root == NULL)
		return;
	
	int c = 0;
	struct node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			c++;
			if(c == n)
				printf("%d ", current->data);
			current = current->right;
		}
		else
		{
			struct node* pre = current->left;
			while(pre->right != NULL && pre->right!= current)
				pre = pre->right;
			
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				c++;
				if(c == n)
					printf("%d ", current->data);
				current = current->right;
			}
		}
	}
}

void nPreorder(struct node* root, int n, int *c)
{
	if(root == NULL)
		return;
	
	(*c)++;
	if(*c == n)
	{
		printf("%d ", root->data);
		return;
	}
	
	nPreorder(root->left, n, c);
	nPreorder(root->right, n, c);
}

void nPostorder(struct node* root, int n, int *c)
{
	if(root == NULL)
		return;
	
	nPostorder(root->left, n, c);
	nPostorder(root->right, n, c);
	
	(*c)++;
	if(*c == n)
	{
		printf("%d ", root->data);
		return;
	}
}

int maxProductLevel(struct node* root)
{
	if(root == NULL)
		return 0;
	
	int max = 0, pro;	
	queue<struct node*> q;
	q.push(root);
	
	while(1)	
	{
		int n = q.size();
		
		if(n == 0)
			return max;
		
		pro = 1;
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			pro *= temp->data;
			if(pro > max)
				max = pro;	
			
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
}

int maxNodesLevel(struct node* root)
{
	if(root == NULL)
		return 0;
	
	int max = 0;	
	queue<struct node*> q;
	q.push(root);
	
	while(1)	
	{
		int n = q.size();
		
		if(n == 0)
			return max;
		
		if(n > max)
			max = n;
		
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
}

int sumMinLevel(struct node* root)
{
	if(root == NULL)
		return 0;
	
	int sum = 0;
	int flag = 0;
	queue<struct node*> q;
	q.push(root);
	
	while(1)
	{
		int n = q.size();
		
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			if(temp->left == NULL && temp->right == NULL)
			{
				sum += temp->data;
				flag = 1;
			}
			
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		if(flag == 1)
			return sum;
	}
}

int maxSumLevel(struct node* root)
{
	if(root == NULL)
		return 0;
	
	int maxsum = INT_MIN;

	queue<struct node*> q;
	q.push(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			break;
		
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			sum += temp->data;
			
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		if(sum > maxsum)
			maxsum = sum;
	}
	return maxsum;
}

int oddNodesLevel(struct node* root)
{
	if(root == NULL)
		return 0;
	
	int oddflag = 1;

	queue<struct node*> q;
	q.push(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			break;
		
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			if(oddflag)
				printf("%d ",temp->data);
			
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		oddflag = !oddflag;
	}
}

int findLevel(struct node* root, int k, int level)
{
	if(root == NULL)
		return 0;
	if(root->data == k)
		return level;
	return findLevel(root->left, k, level + 1) | findLevel(root->right, k, level + 1); 
}

void leftView(struct node* root)
{
	if(root == NULL)
		return;
	
	queue<struct node*> q;
	q.push(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			break;
		
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
			
			if(i == 1)
				printf("%d ", temp->data);
		
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
}

void rightView(struct node* root)
{
	if(root == NULL)
		return;
	
	queue<struct node*> q;
	q.push(root);
	
	while(1)
	{
		int n = q.size();
		
		if(n == 0)
			break;
		
		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();
		
			if(i == n)
				printf("%d ", temp->data);
		
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
}

void topView(struct node* root)
{
	if(root == NULL)
		return;

	int hd = 0;
	map<int, int> m;
	
	queue<pair<struct node*, int> > q;
	q.push(make_pair(root, hd));

	while(!q.empty())
	{
		pair<struct node*, int> temp_pair = q.front();
		q.pop();
		
		struct node* temp = temp_pair.first;
		hd = temp_pair.second;
		
		if(m.find(hd) == m.end())
			m[hd] = temp->data;
		
		if(temp->left != NULL)
			q.push(make_pair(temp->left, hd-1));
		if(temp->right != NULL)
			q.push(make_pair(temp->right, hd+1));
	}
	for(map<int,int>::iterator it = m.begin(); it != m.end(); it++)
		printf("%d ", it->second);
}

void bottomView(struct node* root)
{
	if(root == NULL)
		return;
	
	int hd = 0;
	map<int, int> m;
	
	queue<pair<struct node*, int> > q;
	q.push(make_pair(root, hd));
	
	while(!q.empty())
	{
		pair<struct node*, int> temp_pair = q.front();
		q.pop();
		
		struct node* temp = temp_pair.first;
		hd = temp_pair.second;
		
		m[hd] = temp->data;
		
		if(temp->left != NULL)
			q.push(make_pair(temp->left, hd-1));
		if(temp->right != NULL)
			q.push(make_pair(temp->right, hd+1));
		}
	
	for(map<int,int>::iterator it = m.begin(); it != m.end(); it++)
		printf("%d ", it->second);
}

int kthsmallest(struct node* root, int k)
{
	int count = 0, ksmall = 0;
	struct node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			count++;
			if(count == k)
				ksmall = current->data;
			current = current->right;
		}
		else
		{
			struct node* pre = current->left;
			while(pre->right != NULL && pre->right!= current)
				pre = pre->right;
			
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				count++;
				if(count == k)
					ksmall = current->data;
				current = current->right;
			}
		}
	}
	return ksmall;
}

int kthlargest(struct node* root, int k)
{
	int count = 0, klarge;
	struct node* current = root;
	while(current != NULL)
	{
		if(current->right == NULL)
		{
			count++;
			if(count == k)
				klarge = current->data;
			current = current->left;
		}
		else
		{
			struct node* pre = current->right;
			while(pre->left != NULL && pre->left != current)
				pre = pre->left;
			
			if(pre->left == NULL)
			{
				pre->left = current;
				current = current->right;
			}
			else
			{
				pre->left = NULL;
				count++;
				if(count == k)
					klarge = current->data;
				current = current->left;
			}
		}
	}
	return klarge;
}

int sumLEkthsmallest(struct node* root, int k)
{
	int count = 0, sum = 0;
	struct node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			count++;
			if(count <= k)
				sum += current->data;
			current = current->right;
		}
		else
		{
			struct node* pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;
			
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				count++;
				if(count <= k)
					sum += current->data;
				current = current->right;
			}
		}
	}
	return sum;
}

int sumGEkthlargest(struct node* root, int k)
{
	int count = 0, sum = 0;
	struct node* current = root;
	while(current != NULL)
	{
		if(current->right == NULL)
		{
			count++;
			if(count <= k)
				sum += current->data;
			current = current->left;
		}
		else
		{
			struct node* pre = current->right;
			while(pre->left != NULL && pre->left != current)
				pre = pre->left;
			
			if(pre->left == NULL)
			{
				pre->left = current;
				current = current->right;
			}
			else
			{
				pre->left = NULL;
				count++;
				if(count <= k)
					sum += current->data;
				current = current->left;
			}
		}
	}
	return sum;
}

void range(struct node* root, int k1, int k2)
{
	struct node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			if(current->data >= k1 && current->data <= k2)
				printf("%d ", current->data);
			current = current->right;
		}
		else
		{
			struct node* pre = current->left;
			while(pre->right != NULL && pre->right!= current)
				pre = pre->right;
			
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				if(current->data >= k1 && current->data <= k2)
					printf("%d ", current->data);
				current = current->right;
			}
		}
	}
}

int median(struct node* root)
{
	struct node* current = root;
	struct node* prev;
	int count = sizeIter(root);
	int current_count = 0;
	
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			current_count++;
			
			if(count % 2 != 0 && current_count == (count + 1)/2)
        		return prev->data;
 
            else if (count % 2 == 0 && current_count == (count/2)+1)
                return (prev->data + current->data)/2;
 
			prev = current;
			current = current->right;
		}
		else
		{
			struct node* pre = current->left;
			while(pre->right != NULL && pre->right!= current)
				pre = pre->right;
			
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				prev = pre;
				
				current_count++;
			
				if(count % 2 != 0 && current_count == (count + 1)/2)
	        		return current->data;
	 
	            else if (count % 2 == 0 && current_count == (count/2)+1)
	                return (prev->data + current->data)/2;
	 
				prev = current;
				current = current->right;
			}
		}
	}
}

struct node* inorderSucPre(struct node* root, struct node** suc, struct node** pre, int key)
{
	if(root == NULL)
		return NULL;

	if(key == root->data)
	{
		if(root->left != NULL)
			*pre = findmax(root->left);
		if(root->right != NULL)
			*suc = findmin(root->right);
	}
	else if(key < root->data)
	{
		*suc = root;
		FloorCeilRec(root->left, suc, pre, key);
	}
	else
	{
		*pre = root;
		FloorCeilRec(root->right, suc, pre, key);
	}
}
int check(int n)
{
	if(n < 10 || n > 99)
		return 0;
	else
	{
		int pro_of_digits = (n%10) * (n/10);
		int sum_of_digits = (n%10) + (n/10);
		if(pro_of_digits + sum_of_digits == n)
			return 1;
		else
			return 0;
	}
	
}
void countSplDigit(struct node* root, int *c)
{
	if(root == NULL)
		return;
	
	if(check(root->data))
		*c = *c + 1;
	countSplDigit(root->left, c);
	countSplDigit(root->right, c);
}

struct node* lcaRec(struct node* root, int k1, int k2)
{
	if(root == NULL)
		return NULL;
	
	if(root->data > k1 && root->data > k2)
		return lcaRec(root->left, k1, k2);
	else if(root->data < k1 && root->data < k2)
		return lcaRec(root->right, k1, k2);
	else
		return root;
}

struct node* lcaIter(struct node* root, int k1, int k2)
{
	while(root != NULL)
	{
		if(root->data > k1 && root->data > k2)
			root = root->left;
		else if(root->data < k1 && root->data < k2)
			root = root->right;
		else
			break;
	}
	return root;
}

int distanceFromRoot(struct node* root, int a)
{
	if(root->data == a)
		return 0;
	else if(root->data > a)
		return 1 + distanceFromRoot(root->left, a);
	else if(root->data < a)
		return 1 + distanceFromRoot(root->right, a);
}

int shortDistance(struct node* root, int k1, int k2)
{
	if(root == NULL)
		return 0;
	
	if(root->data > k1 && root->data > k2)
		return shortDistance(root->left, k1, k2);
	else if(root->data < k1 && root->data < k2)
		return shortDistance(root->right, k1, k2);
	else
		return distanceFromRoot(root, k1) + distanceFromRoot(root, k2);
}

int findpairUtil(struct node* root, int sum, unordered_set<int> &set)
{
    if(root == NULL)
        return 0;
 
    if(findpairUtil(root->left, sum, set))
        return 1;
 
    if(set.find(sum - root->data) != set.end()) 
	{
		printf("Pair is found %d %d", sum - root->data, root->data);
        return true;
    }
    else
        set.insert(root->data);
 
    if(findpairUtil(root->right, sum, set))
    	return 1;
}
void findpair(struct node* root, int sum)
{
    unordered_set<int> set;
    if (!findpairUtil(root, sum, set))
    	printf("Do not exist");
}

int deadRec(struct node* root, int min = 1, int max = INT_MAX) 
{ 
	if(root == NULL) 
    	return 0;
       
	if(min == max) 
    	return 1; 
 
	return deadRec(root->left, min, root->data - 1) || deadRec(root->right, root->data + 1, max); 
} 

void rootLeafPath(struct node* root, int path[], int index)
{
	if(root == NULL)
		return;
	
	path[index] = root->data;
	index++;
	
	if(root->left == NULL && root->right == NULL)
	{
		for(int i = 0; i < index; i++)
			printf("%d ", path[i]);
		printf("\n");	
	}
	rootLeafPath(root->left, path, index);
	rootLeafPath(root->right, path, index);
}

int rootLeafPathSum(struct node* root, int sum, int s)
{
	if(root == NULL)
		return 0;
	
	s += root->data;
	
	if(root->left == NULL && root->right == NULL && s == sum)
		return 1;
		
	return rootLeafPathSum(root->left, sum, s) || rootLeafPathSum(root->right, sum, s);
}

void longestRootLeafPathSum(struct node* root, int sum, int* maxsum, int len, int* maxlen)
{
	if(root == NULL)
		return;
	
	sum += root->data;
	len += 1;
	 
	if(root->left == NULL && root->right == NULL)
	{
		if(len > *maxlen) 
		{
	        *maxlen = len;
            *maxsum = sum;
    	} 
		else if(len == *maxlen && sum > *maxsum)
            *maxsum = sum;
    }
		
	longestRootLeafPathSum(root->left, sum, maxsum, len, maxlen);
	longestRootLeafPathSum(root->right, sum, maxsum, len, maxlen);
}

void rootLeafPathMaxSum(struct node* root, int sum, int* maxsum)
{
	if(root == NULL)
		return;
	
	sum += root->data;
	 
	if(root->left == NULL && root->right == NULL)
	{
		if(sum > *maxsum) 
	        *maxsum = sum;
	}
		
	rootLeafPathMaxSum(root->left, sum, maxsum);
	rootLeafPathMaxSum(root->right, sum, maxsum);
}

void fullNodes(struct node* root)
{
	if(root == NULL)
		return;
	
	fullNodes(root->left);
	if(root->left != NULL && root->right != NULL)
		printf("%d ", root->data);
	fullNodes(root->right);
}

void printKdistance(struct node *root, int k)
{
    if(root == NULL)
        return;
        
    if(k == 0)
    {
        printf("%d ", root->data);
        return;
    }
    printKdistance(root->left, k - 1);
    printKdistance(root->right, k - 1);
}

int main()
{
	int key, choice, k, k1, k2, c, oldVal, newVal, sum, n;
	int maxsum = INT_MIN, maxlen = INT_MIN;
					 
	struct node* root = NULL;
	struct node* temp;
	struct node* suc = NULL, *pre = NULL;
	struct node* floor = NULL, *ceil = NULL;
	struct node* lca = NULL;
	
	int path[100];				
	
	scanf("%d", &key);
	root = insert(root, key);
	
	while(1)
	{
		printf("\nBinary Search Tree Operations:");
		printf("\n1.Insertion");
		printf("\n2.Search - Recur");
		printf("\n3.Search - Iter");
		printf("\n4.Delete Node");
		printf("\n5.Delete Leaf Nodes");
		printf("\n6.Delete Leaf Nodes with K value");
		printf("\n7.Delete Entire Tree");
		printf("\n8.Modify");
		printf("\n9.Minimum");
		printf("\n10.Maximum");
		printf("\n11.Floor and Ceil - Recur");
		printf("\n12.Floor and Ceil - Iter");
		printf("\n13.Size(No of elements) - Recur");
		printf("\n14.Size(No of elements) - Iter");
		printf("\n15.Height/Depth - Recur");
		printf("\n16.Height/Depth - Iter");
		printf("\n17.Check if balanced");
		printf("\n18.No of leaves - Recur");
		printf("\n19.No of leaves - Iter");
		printf("\n20.No of non leaves");
		printf("\n21.No of full nodes");
		printf("\n22.No of half nodes");
		printf("\n23.Sum of all nodes");
		printf("\n24.Sum of all left leaf nodes");
		printf("\n25.Sum of all right leaf nodes");
		printf("\n26.Sum of leaf nodes");
		printf("\n27.Inorder");
		printf("\n28.Preorder");
		printf("\n29.Postorder");
		printf("\n30.Morris(Inorder without stack and recursion)");
		printf("\n31.Iterative Preorder");
		printf("\n32.Iterative Postorder");
		printf("\n33.Reverse Morris");
		printf("\n34.Level Order");
		printf("\n35.Level Order line by line");
		printf("\n36.Level Order spiral");
		printf("\n37.Level Order direction change for every 2 traversals");
		printf("\n38.Reverse Level Order Traversal");
		printf("\n39.Vertical Order Traversal");
		printf("\n40.Boundary Traversal");
		printf("\n41.nth Node in Inorder");
		printf("\n42.nth Node in Preorder");
		printf("\n43.nth Node in Postorder");
		printf("\n44.Maximum Product level");
		printf("\n45.Level with maximum nodes");
		printf("\n46.Sum of leaf nodes at minimum level");
		printf("\n47.Level with maximum sum");
		printf("\n48.Nodes at odd level");
		printf("\n49.Level of a given node");
		printf("\n50.Left view");
		printf("\n51.Right view");
		printf("\n52.Top view");
		printf("\n53.Bottom view");
		printf("\n54.Kth Smallest");
		printf("\n55.Kth Largest");
		printf("\n56.Sum of elements lesser than or equal to kth smallest element");
		printf("\n57.Sum of elements greater than or equal to kth largest element");
		printf("\n58.Print keys within range");
		printf("\n59.Median");
		printf("\n61.Inorder Successor and Inorder Predecessor");
		printf("\n62.Count Special Digits");
		printf("\n63.Lowest Common Ancestor - Recur");
		printf("\n64.Lowest Common Ancestor - Iter");
		printf("\n65.Shortest Distance between two nodes");
		printf("\n66.Pairs with given sum");
		printf("\n67.Contains Dead End - Recur");
		printf("\n69.Root to leaf paths");
		printf("\n70.Root to leaf path with given sum");
		printf("\n71.Sum of the longest Root to leaf path");
		printf("\n72.Root to leaf path with maximum sum");
		printf("\n76.Full nodes");
		printf("\n77.Print nodes at a distance k from root");
		printf("\n78.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: scanf("%d", &key);
					root = insert(root, key);
					inorder(root);
					break;
			case 2: scanf("%d", &key);
					if(searchRec(root, key))
						printf("Found");
					else
						printf("Not found");
					break;
			case 3: scanf("%d", &key);
					if(searchIter(root, key))
						printf("Found");
					else
						printf("Not found");
					break;
			case 4: scanf("%d", &key);
					root = deleteNode(root, key);
					inorder(root);
					break;
			case 5: root = deleteLeaf(root);
					inorder(root);
					break;
			case 6: scanf("%d", &k);
					root = deleteLeafWithK(root, k);
					inorder(root);
					break;
			case 7: root = deleteTree(root);
					inorder(root);
					break;
			case 8: scanf("%d%d", &oldVal, &newVal);
					root = deleteNode(root, oldVal);
					root = insert(root, newVal);
					inorder(root);
					break;
			case 9: temp = findmin(root);
					printf("%d", temp->data);
					break;
			case 10: temp = findmax(root);
					 printf("%d", temp->data);
					 break;
			case 11: scanf("%d", &key);
					 FloorCeilRec(root, &floor, &ceil, key);
					 printf("Floor: %d\tCeil: %d", floor->data, ceil->data);
					 break;
			case 12: scanf("%d", &key);
					 FloorCeilIter(root, &floor, &ceil, key);
					 printf("Floor: %d\tCeil: %d", floor->data, ceil->data);
					 break;
			case 13: printf("%d", sizeRec(root));
					 break;
			case 14: printf("%d", sizeIter(root));
					 break;
			case 15: printf("%d", heightRec(root));
					 break;
			case 16: printf("%d", heightIter(root));
					 break;
			case 17: if(isBalanced(root))
						printf("Balanced");
					 else
					 	printf("Not balanced");
					 break;
			case 18: printf("%d", leafCountRec(root));
					 break;
			case 19: printf("%d", leafCountIter(root));
					 break;
			case 20: printf("%d", nonleafCount(root));
					 break;
			case 21: printf("%d", fullnodeCount(root));
				     break;
			case 22: printf("%d", halfnodeCount(root));
				     break;
			case 23: printf("%d",sumNodes(root));
					 break;
			case 24: printf("%d",sumLeftLeafNodes(root));
					 break;
			case 25: printf("%d",sumRightLeafNodes(root));
					 break;
			case 26: printf("%d",sumLeafNodes(root));
					 break;
			case 27: inorder(root);
					 break;
			case 28: preorder(root);
					 break;
			case 29: postorder(root);
					 break;
			case 30: morris(root);
					 break;
			case 31: iterativePreorder(root);
					 break;
			case 32: iterativePostorder(root);
					 break;
			case 33: reverseMorris(root);
					 break;
			case 34: levelOrder(root);
					 break;
			case 35: levelOrder1by1(root);
					 break;
			case 36: levelOrderSpiral(root);
					 break;
			case 37: levelOrderDirectionChange(root);
					 break;
			case 38: reverseLevelOrder(root);
					 break;
			case 39: verticalOrder(root);
				  	 break;
			case 40: boundary(root);
					 break;
			case 41: scanf("%d", &n);
					 nInorder(root, n);
					 break;
			case 42: scanf("%d", &n);
					 c = 0;
					 nPreorder(root, n, &c);
					 break;
			case 43: scanf("%d", &n);
					 c = 0;
					 nPostorder(root, n, &c);
					 break;
			case 44: printf("%d", maxProductLevel(root));
					 break;
			case 45: printf("%d", maxNodesLevel(root));
				     break;
			case 46: printf("%d", sumMinLevel(root));
					 break;
			case 47: printf("%d", maxSumLevel(root));
				     break;
			case 48: oddNodesLevel(root);
				     break;
			case 49: scanf("%d", &k);
					 printf("%d", findLevel(root, k, 0));
					 break;
			case 50: leftView(root);
					 break;
			case 51: rightView(root);
					 break;
			case 52: topView(root);
					 break;
			case 53: bottomView(root);
					 break;
			case 54: scanf("%d", &k);
					 printf("%d", kthsmallest(root, k));
					 break;
			case 55: scanf("%d", &k);
					 printf("%d", kthlargest(root, k));
					 break;
			case 56: scanf("%d", &k);
					 printf("%d", sumLEkthsmallest(root, k));
					 break;
			case 57: scanf("%d", &k);
					 printf("%d", sumGEkthlargest(root, k));
					 break;
			case 58: scanf("%d%d", &k1, &k2);
					 range(root, k1, k2);
					 break;
			case 59: printf("%d", median(root));
					 break;
			case 61: scanf("%d", &key);
				     inorderSucPre(root, &suc, &pre, key);
					 printf("Inorder Successor: %d\tPreorder Successor: %d", suc->data, pre->data);
					 break;
			case 62: c = 0;
					 countSplDigit(root, &c);
					 printf("%d", c);
					 break;
			case 63: scanf("%d%d", &k1, &k2);
					 lca = lcaRec(root, k1, k2);
					 printf("%d", lca->data);
					 break;
			case 64: scanf("%d%d", &k1, &k2);
					 lca = lcaIter(root, k1, k2);
					 printf("%d", lca->data);
					 break;
			case 65: scanf("%d%d", &k1, &k2);
					 printf("%d", shortDistance(root, k1, k2));
					 break;	
			case 66: scanf("%d", &sum);
					 findpair(root, sum);
					 break;
			case 67: if(deadRec(root))
                    	printf("Dead end");
                     else
                    	printf("No dead end");
					 break;    
			case 69: rootLeafPath(root, path, 0);
					 break;
			case 70: scanf("%d", &sum);
					 if(rootLeafPathSum(root, sum, 0))
					 	printf("Path exists");
					 else
						printf("Path doesnt exist");
					 break;
			case 71: longestRootLeafPathSum(root, 0, &maxsum, 0, &maxlen);
					 printf("%d", maxsum);
					 break;
			case 72: maxsum = INT_MIN;
					 rootLeafPathMaxSum(root, 0, &maxsum);
					 printf("%d", maxsum);
					 break;
			case 76: fullNodes(root);
					 break;
			case 77: scanf("%d", &k);
					 printKdistance(root, k);
					 break;
			case 78: goto exit;
		}
	}
	exit:
		return 0;
}

