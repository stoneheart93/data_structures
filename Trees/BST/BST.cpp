#include<iostream>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

#define INIT_MIN 9999999

struct node
{
    struct node *left;
    int no;
    struct node *right;
}*root;

struct node* insert(struct node* root, int key)
{
    if(root == NULL)
	{
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
	    newnode->no = key;
	    newnode->left = NULL;
	    newnode->right = NULL;        
	    return newnode;
	}
	
	if(key < root->no)
    	root->left  = insert(root->left, key);
    else if (key > root->no)
        root->right = insert(root->right, key);   
 	
	return root;
}

int search(struct node* root, int key)
{
    if(root == NULL)
		return 0;
	if(root->no == key)
    	return 1;
	else if(key < root->no)
    	return search(root->left, key);
    else 
		return search(root->right, key);
}

int searchIter(struct node* root, int key)
{
    while(root != NULL)
    {
        if(key < root->no)
            root = root->left; 
        else if(key > root->no)
            root = root->right;
        else
            return 1;
    }
    return 0;
}

struct node* findmin(struct node* root)
{      
    struct node* current = root;
    while(current->left != NULL)
        current = current->left;
    return current;
}

struct node* findmax(struct node* root)
{      
    struct node* current = root;
    while(current->right != NULL)
        current = current->right;
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if(root == NULL) 
		return root;
 	
	if(key < root->no)
    	root->left = deleteNode(root->left, key);
 	else if(key > root->no)
        root->right = deleteNode(root->right, key);
 	else
    {
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
		else
		{
			struct node* temp = findmin(root->right);
			root->no = temp->no;
			root->right = deleteNode(root->right, temp->no);
		}
    }
    return root;
}

void deleteTree(struct node* root) 
{
    if(root == NULL) 
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    printf("\n Deleting node: %d", root->no);
    free(root);
} 

struct node* deleteLeaf(struct node* root)
{
    if(root->left == NULL && root->right == NULL) 
	{
        free(root);
        return NULL;
    }
    root->left = deleteLeaf(root->left);
    root->right = deleteLeaf(root->right);
    return root;
}

void inorder(struct node* root)
{    
    if(root == NULL)
    	return;
    
	inorder(root->left);
    printf("\n %d", root->no);
    inorder(root->right);
}
void preorder(struct node* root)
{    
    if(root != NULL)
    	return;
    	
    printf("\n %d", root->no);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root)
{    
    if(root != NULL)
    	return;
    	
    postorder(root->left);
    postorder(root->right);
    printf("\n %d", root->no);
}

int size(struct node* root) //no of elements
{
    if(root == NULL) 
    	return 0;
    else    
        return(size(root->left) + 1 + size(root->right));  
}

int sizeIter(struct node* root) //no of elements
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
		{
            q.push(temp->left);
            count++;
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
            count++;
        }
    }
    return count;
}

int max(int a, int b)
{
	return (a > b)? a: b;
}
int height(struct node* root) 
{
    if(root == NULL) 
        return 0;
    else
	    return 1 + max(height(root->left), height(root->right));
} 

int heightIter(struct node* root) 
{
	int height = 0;
	queue<struct node*> q;
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

void mirror(struct node* root) 
{
    if(root == NULL) 
        return;  
    
	struct node* temp;
    mirror(root->left);
    mirror(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
} 

void swap(int &a, int &b)
{
	int temp = a;
	a= b;
	b = temp;
}
int mirrorIter(struct node* root)
{
    if(root == NULL)
    	return 0;
 
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
 
		swap(temp->left, temp->right);
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

void printPathsRecur(struct node* root, int path[], int pathLen) 
{
	int i;
	if(root == NULL) 
		return;
 
	path[pathLen] = root->no;
	pathLen++;
 
	if (root->left==NULL && root->right==NULL) 
	{
    	for(i = 0; i < pathLen; i++)
            printf("%d ", path[i]);
        printf("\n");
	}
	else
	{
		printPathsRecur(root->left, path, pathLen);
    	printPathsRecur(root->right, path, pathLen);
	}
}
void printPaths(struct node* root) 
{
    int path[1000];
    printPathsRecur(root, path, 0);
}

struct node* lca(struct node* root, int n1, int n2)
{
    if(root == NULL) 
		return NULL;
 
	if(root->no > n1 && root->no > n2)
        return lca(root->left, n1, n2);
 
    if(root->no < n1 && root->no < n2)
        return lca(root->right, n1, n2);
 
    return root;
}

struct node *lcaIter(struct node* root, int n1, int n2)
{
    while(root != NULL)
    {
        if(root->no > n1 && root->no > n2)
           root = root->left;
        else if(root->no < n1 && root->no < n2)
           root = root->right;
        else 
			break;
    }
    return root;
}

int getLeafCount(struct node* root)
{
    if(root==NULL)       
        return 0;
    else if(root->left==NULL && root->right==NULL)      
        return 1;            
    else
        return getLeafCount(root->left) + getLeafCount(root->right);      
}    

int getLeafCountIter(struct node* root)
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
 
int height(struct node* root, int& ans)
{
    if(root == NULL)
    	return 0;
 
    int lheight = height(root->left, ans);
    int rheight = height(root->right, ans);
 
    ans = max(ans, 1 + lheight + rheight);
 
    return 1 + max(lheight, rheight);
}
int diameter(struct node* root)
{
    if(root == NULL)
    	return 0;
    int ans = INIT_MIN;
    int height_of_tree = height(root, ans);
    return ans;
}

int isSumProperty(struct node* root)
{
	int left_data = 0,  right_data = 0;
	
	if(root == NULL || (root->left == NULL && root->right == NULL))
    	return 1;
	else
	{
    	if(root->left != NULL)
			left_data = root->left->no;
 
    	if(root->right != NULL)
			right_data = root->right->no;
 
    	if((root->no == left_data + right_data) && isSumProperty(root->left) && isSumProperty(root->right))
			return 1;
		else
			return 0;	
	}
}

void MorrisTraversal(struct node *root)
{
	struct node *curr, *prev;
 
	if(root == NULL)
    	return; 
 
	curr = root;
	while(curr != NULL)
	{                 
    	if(curr->left == NULL)
    	{
			printf("%d ", curr->no);
			curr = curr->right;      
    	}    
    	else
    	{
    		prev = curr->left;
    		while(prev->right != NULL && prev->right != curr)
        		prev = prev->right;
			if(prev->right == NULL)
			{
        		prev->right = curr;
        		curr = curr->left;
			}
			else 
			{
    			prev->right = NULL;
        		printf("%d ",curr->no);
        		curr = curr->right;      
			}
		}
	}
}

int hasPathSum(struct node* root, int sum)
{
	if(root == NULL)
		return (sum == 0);
	
	else
	{
    	int ans = 0;  
		int subSum = sum - root->no;
		if(subSum == 0 && root->left == NULL && root->right == NULL)
			return 1;
  
    	if(root->left)
			ans = ans || hasPathSum(root->left, subSum);
    	if(root->right)
			ans = ans || hasPathSum(root->right, subSum);
  
    	return ans;
	}
}

int findFloor(struct node* root, int N)
{
    if(root->left == NULL && root->right == NULL && root->no > N)
        return -1;

    if((root->no <= N && root->right == NULL) || (root->no <= N && root->right->no > N))
        return root->no;
 
    if(root->no >= N)
        return findFloor(root->left, N);
    else
        return findFloor(root->right, N);
}

int findFloorIter(struct node* root, int N)
{
    struct node *curr = root, *ans = NULL;
    while(curr) 
	{
        if(curr->no <= N) 
		{
            ans = curr;
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
    if(ans)
        return ans->no;
    else
    	return -1;
}

int findpairUtil(struct node* root, int sum, unordered_set<int> &set)
{
    if(root == NULL)
        return 0;
 
    if(findpairUtil(root->left, sum, set))
        return 1;
 
    if(set.find(sum - root->no) != set.end()) 
	{
		printf("Pair is found %d %d", sum - root->no, root->no);
        return true;
    }
    else
        set.insert(root->no);
 
    return findpairUtil(root->right, sum, set);
}
void findpair(struct node* root, int sum)
{
    unordered_set<int> set;
    if (!findpairUtil(root, sum, set))
    	printf("Do not exist");
}

int dead(struct node* root, int min = 1, int max = INT_MAX) 
{ 
	if(root == NULL) 
    	return 0;
       
	if(min == max) 
    	return 1; 
 
	return dead(root->left, min, root->no - 1) || dead(root->right, root->no + 1, max); 
} 

int main()
{     
    int key, choice, n1, n2, sum, N;
    struct node* temp;
    
	printf("\n Enter the data: ");
    scanf("%d", &key);
	root = insert(root, key);
    
    while(1)
    {
        printf("\n 1.Insert");
        printf("\n 2.Search");
        printf("\n 3.Search - Iterative");
        printf("\n 4.Delete");
        printf("\n 5.Delete Tree");
        printf("\n 6.Delete Leaf");
        printf("\n 7.Display");
        printf("\n 8.Size");
        printf("\n 9.Size - Iterative");
        printf("\n 10.Maxdepth");
        printf("\n 11.Maxdepth - Iterative");
        printf("\n 12.Mirror");
        printf("\n 13.Mirror - Iterative");
        printf("\n 14.Print paths");
        printf("\n 15.Least Common Ancestor");
        printf("\n 16.Least Common Ancestor - Iterative");
        printf("\n 17.Leaf count");
        printf("\n 18.Leaf count - Iterative");
        printf("\n 19.Diameter");
        printf("\n 20.Children Sum Property");
        printf("\n 21.Inorder traversal without stack and recursion");
        printf("\n 22.Root to leaf path sum equal to a given number");
        printf("\n 23.Largest number in BST less than or equal to N");
        printf("\n 24.Largest number in BST less than or equal to N - Iterative");
        printf("\n 25.Pair with given sum");
        printf("\n 26.Dead End");
		printf("\n 27.Dead End - Iterative");
		printf("\n 28.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {      
            case 1: printf("\n Enter the data to be inserted: ");
            		scanf("%d", &key);
					insert(root, key);
                	printf("\n Calling inorder traversal");
                    inorder(root);
                    break;
            case 2: printf("\n Enter the key node to be found: ");
                    scanf("%d", &key);
                    if(search(root, key))
                    	printf("Found");
                    else
                    	printf("Not found");
					break;
            case 3: printf("\n Enter the key node to be found: ");
                    scanf("%d", &key);
                    if(searchIter(root, key))
                    	printf("Found");
                    else
                    	printf("Not found");
					break;
            case 4: printf("\n Enter the key node to be deleted: ");
                    scanf("%d", &key);
                    deleteNode(root, key);
                    inorder(root);
                    break;
            case 5: deleteTree(root);
                    break; 
            case 6: deleteLeaf(root);
            		inorder(root);
                    break; 
            case 7: printf("\n Printing inorder traversal");
                    inorder(root);
                    printf("\n Printing postorder traversal");
                    postorder(root);
                    printf("\n Printing preorder traversal");
                    preorder(root);
                    break;
            case 8: printf("\n Size: %d", size(root));
                    break; 
            case 9: printf("\n Size: %d", sizeIter(root));
                    break; 
            case 10: printf("\n Maxdepth: %d", height(root));
                    break;
            case 11: printf("\n Maxdepth: %d", heightIter(root));
                    break;
            case 12: mirror(root);
                     inorder(root);
                     break;
            case 13: mirrorIter(root);
                     inorder(root);
                     break;
            case 14: printPaths(root);
                     break;
            case 15: printf("\n Enter two numbers in the tree: ");
                     scanf("%d%d", &n1, &n2);
                     temp = lca(root, n1, n2);
                     printf("\n Least common ancestor: %d", temp->no);
                     break;
            case 16: printf("\n Enter two numbers in the tree: ");
                     scanf("%d%d", &n1, &n2);
                     temp = lcaIter(root, n1, n2);
                     printf("\n Least common ancestor: %d", temp->no);
                     break;
            case 17: printf("\n No of leafs: %d", getLeafCount(root));
                     break;
            case 18: printf("\n No of leafs: %d", getLeafCountIter(root));
                     break;
            case 19: printf("%d", diameter(root));
                     break;
            case 20: if(isSumProperty(root))
            			printf("Holds");
            		 else
            			printf("Doesnt hold");
            		 break;
        	case 21: MorrisTraversal(root);
                     break;
            case 22: printf("\n Enter the sum: ");
            	  	 scanf("%d", &sum);
					 if(hasPathSum(root, sum))
            			printf("\n Path exists");
            		 else	
            		 	printf("\n Doesnt exist");
            		 break;
            case 23: printf("\n Enter N:");
					 scanf("%d", &N);
					 printf("%d", findFloor(root, N));
            		 break;
            case 24: printf("\n Enter N:");
					 scanf("%d", &N);
					 printf("%d", findFloorIter(root, N));
            		 break;
            case 25: printf("\n Enter the sum: ");
            	  	 scanf("%d", &sum);
					 findpair(root,sum);
					 break;
            case 26: if(dead(root))
                    	printf("Dead end");
                     else
                    	printf("No dead end");
					 break;
            /*case 20: if(deadIter(root))
                    	printf("Dead end");
                     else
                    	printf("No dead end");
					 break;*/
            case 28: goto exit;
		}
	}
    exit:
	return 0;
}

