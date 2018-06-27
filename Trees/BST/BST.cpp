#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<unordered_set>
#include<set>
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

void deleteTree(struct node* root)
{
	if(root == NULL)
		return;
		
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
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
	else
		return sizeRec(root->left) + 1 + sizeRec(root->right);
}

int max(int a, int b)
{
	return (a > b)? a: b;
}
int heightRec(struct node* root) 
{
    if(root == NULL) 
        return 0;
    else
	    return 1 + max(heightRec(root->left), heightRec(root->right));
} 

int leafCountRec(struct node* root)
{
    if(root == NULL)       
        return 0;
	
	if(root->left == NULL && root->right == NULL)      
        return 1;            
    else
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

void mirrorRec(struct node* root)
{
	if(root == NULL)
		return;
		
	mirrorRec(root->left);
	mirrorRec(root->right);
	
	struct node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void mirrorIter(struct node* root)
{
	if(root == NULL)
		return;
	
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		struct node* temp = q.front();
		q.pop();
		
		struct node* swap_temp = temp->left;
		temp->left = temp->right;
		temp->right = swap_temp;
		
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
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
	
	while(!q.empty())
	{
		int n = q.size();
		
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
	
	int flip = 0;
	
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		int n = q.size();
		
		struct node* temp = q.front();
		q.pop();
			
		printf("%d ", temp->data);
			
		if(flip == 0)
		{
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
		else
		{
			if(temp->right != NULL)
				q.push(temp->right);
			if(temp->left != NULL)
				q.push(temp->left);
		}
		flip = !flip;
	}
}

int maxProductLevel(struct node* root)
{
	if(root == NULL)
		return 0;
	
	int max = 0, pro;	
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty())	
	{
		int n = q.size();
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
	return max;
}

void leftView(struct node* root)
{
	if(root == NULL)
		return;
	
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		int n = q.size();
		
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
	
	while(!q.empty())
	{
		int n = q.size();
		
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


/*
int median(struct node* root)
{
	struct node* current = root;
	int count = size(root);
	int current_count = 0;
	
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			current_count++;
			if(count % 2 != 0 && current_count == (count + 1)/2)
        		return prev->data;
 
            // Even case
            else if (count % 2 == 0 && currCount == (count/2)+1)
                return (prev->data + current->data)/2;
 
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
*/
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

int main()
{
	int key, choice, k, k1, k2, c, oldVal, newVal, sum, n;
	struct node* root = NULL;
	struct node* temp;
	struct node* suc = NULL, *pre = NULL;
	struct node* floor = NULL, *ceil = NULL;
	struct node* lca = NULL;				
	
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
		printf("\n15.Height/Depth - Recur");
		printf("\n17.No of leaves - Recur");
		printf("\n18.No of leaves - Iter");
		printf("\n19.Mirror - Recur");
		printf("\n20.Mirror - Iter");
		printf("\n25.Inorder");
		printf("\n26.Preorder");
		printf("\n27.Postorder");
		printf("\n28.Morris(Inorder without stack and recursion)");
		printf("\n29.Reverse Morris");
		printf("\n30.Level Order");
		printf("\n31.Level Order line by line");
		printf("\n32.Level Order spiral");
		printf("\n33.nth Node in Preorder");
		printf("\n34.nth Node in Postorder");
		printf("\n35.Maximum Product level");
		printf("\n39.Left view");
		printf("\n40.Right view");
		printf("\n41.Kth Smallest");
		printf("\n42.Kth Largest");
		printf("\n43.Sum of elements lesser than or equal to kth smallest element");
		printf("\n44.Sum of elements greater than or equal to kth largest element");
		printf("\n45.Print keys within range");
		printf("\n46.Median");
		printf("\n51.Inorder Successor and Inorder Predecessor");
		printf("\n52.Count Special Digits");
		printf("\n53.Lowest Common Ancestor - Recur");
		printf("\n54.Lowest Common Ancestor - Iter");
		printf("\n55.Shortest Distance between two nodes");
		printf("\n56.Pairs with given sum");
		printf("\n57.Contains Dead End - Recur");
		printf("\n67.Exit\n");
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
			case 7: deleteTree(root);
					root = NULL;
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
			case 15: printf("%d", heightRec(root));
					 break;
			case 17: printf("%d", leafCountRec(root));
					 break;
			case 18: printf("%d", leafCountIter(root));
					 break;
			case 19: mirrorRec(root);
					 inorder(root);
					 deleteTree(root); // since it wont be a bst anymore
					 break;
			case 20: mirrorIter(root);
					 inorder(root);
					 deleteTree(root); // since it wont be a bst anymore
					 break;
			case 25: inorder(root);
					break;
			case 26: preorder(root);
					break;
			case 27: postorder(root);
					 break;
			case 28: morris(root);
					 break;
			case 29: reverseMorris(root);
					 break;
			case 30: levelOrder(root);
					 break;
			case 31: levelOrder1by1(root);
					 break;
			case 32: levelOrderSpiral(root);
					 break;
			case 33: scanf("%d", &n);
					 c = 0;
					 nPreorder(root, n, &c);
					 break;
			case 34: scanf("%d", &n);
					 c = 0;
					 nPostorder(root, n, &c);
					 break;
			case 35: printf("%d", maxProductLevel(root));
					 break;
			case 39: leftView(root);
					 break;
			case 40: rightView(root);
					 break;
			case 41: scanf("%d", &k);
					 printf("%d", kthsmallest(root, k));
					 break;
			case 42: scanf("%d", &k);
					 printf("%d", kthlargest(root, k));
					 break;
			case 43: scanf("%d", &k);
					 printf("%d", sumLEkthsmallest(root, k));
					 break;
			case 44: scanf("%d", &k);
					 printf("%d", sumGEkthlargest(root, k));
					 break;
			case 45: scanf("%d%d", &k1, &k2);
					 range(root, k1, k2);
					 break;
			/*case 29: printf("%d", median(root));
					 break;*/
			case 51: scanf("%d", &key);
				     inorderSucPre(root, &suc, &pre, key);
					 printf("Inorder Successor: %d\tPreorder Successor: %d", suc->data, pre->data);
					 break;
			case 52: c = 0;
					 countSplDigit(root, &c);
					 printf("%d", c);
					 break;
			case 53: scanf("%d%d", &k1, &k2);
					 lca = lcaRec(root, k1, k2);
					 printf("%d", lca->data);
					 break;
			case 54: scanf("%d%d", &k1, &k2);
					 lca = lcaIter(root, k1, k2);
					 printf("%d", lca->data);
					 break;
			case 55: scanf("%d%d", &k1, &k2);
					 printf("%d", shortDistance(root, k1, k2));
					 break;	
			case 56: scanf("%d", &sum);
					 findpair(root, sum);
					 break;
			case 57: if(deadRec(root))
                    	printf("Dead end");
                     else
                    	printf("No dead end");
					 break;    
			case 67: goto exit;
		}
	}
	exit:
		return 0;
}
