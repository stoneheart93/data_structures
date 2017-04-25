#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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

struct node* search(struct node* root, int key)
{
    if(root == NULL)
	{
		printf("Element not found");
       	return root;
	} 
	
	if(root->no == key)
    {
    	printf("Element found");
       	return root;
	}
    else if(key < root->no)
       return search(root->left, key);
    else 
		return search(root->right, key);
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
 		
		struct node* temp = findmin(root->right);
		root->no = temp->no;
		root->right = deleteNode(root->right, temp->no);
    }
    return root;
}

void inorder(struct node* root)
{    
    if(root != NULL)
    {     
    	inorder(root->left);
        printf("\n %d", root->no);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{    
    if(root != NULL)
    {     
        printf("\n %d", root->no);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{    
    if(root != NULL)
    {     
        postorder(root->left);
        postorder(root->right);
        printf("\n %d", root->no);         
    }
}

int size(struct node* root) //no of elements
{
    if(root == NULL) 
    	return 0;
    else    
        return(size(root->left) + 1 + size(root->right));  
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

void deleteTree(struct node* root) 
{
    if(root == NULL) 
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    printf("\n Deleting node: %d", root->no);
    free(root);
} 

void mirror(struct node* root) 
{
    if(root==NULL) 
        return;  
    
	struct node* temp;
    mirror(root->left);
    mirror(root->right);
    temp=root->left;
    root->left=root->right;
    root->right=temp;
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

int getLeafCount(struct node* root)
{
    if(root==NULL)       
        return 0;
    else if(root->left==NULL && root->right==NULL)      
        return 1;            
    else
        return getLeafCount(root->left) + getLeafCount(root->right);      
}    

int diameter(struct node* root)
{
	if(root == NULL)
    	return 0;
	
	int lheight = height(root->left);
	int rheight = height(root->right);
 
	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);
	
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
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

int main()
{     
    int key, choice, n1, n2, sum;
    
	printf("\n Enter the data: ");
    scanf("%d", &key);
	root = insert(root, key);
    
    while(1)
    {
        printf("\n 1.Insert");
        printf("\n 2.Search");
        printf("\n 3.Delete");
        printf("\n 4.Display");
        printf("\n 5.Size");
        printf("\n 6.Maxdepth");
        printf("\n 7.Delete Tree");
        printf("\n 8.Mirror");
        printf("\n 9.Print paths");
        printf("\n 10.Least Common Ancestor");
        printf("\n 11.Leaf count");
        printf("\n 12.Diameter");
        printf("\n 13.Children Sum Property");
        printf("\n 14.Inorder traversal without stack and recursion");
        printf("\n 15.Root to leaf path sum equal to a given number");
		printf("\n 26.Exit");
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
                    search(root, key);
					break;
            case 3: printf("\n Enter the key node to be deleted: ");
                    scanf("%d", &key);
                    deleteNode(root, key);
                    inorder(root);
                    break;
            case 4: printf("\n Printing inorder traversal");
                    inorder(root);
                    printf("\n Printing postorder traversal");
                    postorder(root);
                    printf("\n Printing preorder traversal");
                    preorder(root);
                    break;
            case 5: printf("\n Size: %d", size(root));
                    break; 
            case 6: printf("\n Maxdepth: %d", height(root));
                    break;
            case 7: deleteTree(root);
                    break; 
            case 8: mirror(root);
                    inorder(root);
                    break;
            case 9: printPaths(root);
                    break;
            case 10: printf("\n Enter two numbers in the tree: ");
                     scanf("%d%d", &n1, &n2);
                     struct node* temp = lca(root, n1, n2);
                     printf("\n Least common ancestor: %d", temp->no);
                     break;
            case 11: printf("\n No of leafs: %d", getLeafCount(root));
                     break;
            case 12: printf("%d", diameter(root));
                     break;
            case 13: if(isSumProperty(root))
            			printf("Holds");
            		 else
            			printf("Doesnt hold");
            		 break;
        	case 14: MorrisTraversal(root);
                     break;
            case 15: printf("\n Enter the sum: ");
            	  	 scanf("%d", &sum);
					 if(hasPathSum(root, sum))
            			printf("\n Path exists");
            		 else	
            		 	printf("\n Doesnt exist");
            		 break;
        	case 26: goto exit;
		}
	}
    exit:
	return 0;
}

