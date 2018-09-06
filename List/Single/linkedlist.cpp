#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include <bits/stdc++.h>

struct node
{
	int data;
	struct node *next;

};

void addatbeg(struct node** head)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted at beginning: ");
	scanf("%d", &temp->data);
	temp->next = *head;
	*head = temp;
}

void addatend(struct node** head)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted at end: ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	
	if((*head) == NULL)
	{
		*head = temp;
		return;
	}
	
	struct node* rider = *head;
	while(rider->next != NULL)
		rider = rider->next;  
	rider->next = temp;
}


void addatmid(struct node* head)
{
	int num;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted at middle: ");
	scanf("%d", &temp->data);
	printf("Enter the data succeeding the number to be inserted: ");
	scanf("%d", &num);
	while(head->next->data != num)
		head = head->next;
	temp->next = head->next;
	head->next = temp;
}

void sorted_insert(struct node** head)
{
	struct node* rider = *head;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted in sorted way: ");
	scanf("%d", &temp->data);
	if(rider == NULL || temp->data <= rider->data)
	{
		temp->next = rider;
		*head = temp;
	}
	else
	{
		while(rider->next != NULL && temp->data > rider->next->data)
			rider = rider->next;
		temp->next = rider->next;
		rider->next = temp;
	}
}

void insert_middle(struct node* head)
{
	if(head == NULL)
		return;

	struct node* temp = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &temp->data);

	struct node* slowptr = head;
	struct node* fastptr = head;

	while(fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}

	temp->next = slowptr->next;
	slowptr->next = temp;
}

void insert_nth_from_last(struct node* head, int n)
{
	if(head == NULL)
		return;

	struct node* temp = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &temp->data);

	struct node* slowptr = head;
	struct node* fastptr = head;

	for(int i = 1; i <= n - 1; i ++)
		fastptr = fastptr->next;

	while(fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}

	temp->next = slowptr->next;
	slowptr->next = temp;    
}

void delatbeg(struct node** head)
{
	struct node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void delatend(struct node** head)
{
	struct node* temp;
	if((*head)->next == NULL)
	{
		temp = *head;
		free(temp);
		*head = NULL;
	}
	
	struct node* rider = *head;
	while(rider->next->next != NULL)         
		rider = rider->next;
	temp = rider->next;
	rider->next = NULL;
	free(temp);
}

void delatmid(struct node* head)
{
	int num;
	struct node* temp;
	printf("Enter the number to be deleted: ");
	scanf("%d", &num);
	while(head->next->data != num)
		head = head->next;
	temp = head->next;
	head->next = temp->next;
	free(temp);
}   

void delMidNode(struct node** head)
{
	if(*head == NULL)
		return;

	struct node* slowptr = *head;
	struct node* fastptr = *head;
	struct node* prev = NULL;

	while(fastptr != NULL && fastptr->next != NULL)
	{
		prev = slowptr;
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}

	prev->next = slowptr->next;
	free(slowptr);
}

void delalt(struct node* head)
{
	if(head == NULL)
		return;

	struct node* prev = head; 
	struct node* node = head->next;
	while(prev != NULL && node != NULL)
	{
		prev->next = node->next;   
		free(node);
		prev = prev->next;
		if(prev != NULL)
			node = prev->next;
	}      
}

void delaltRec(struct node* head)
{
	if(head == NULL)
		return;

	struct node* node = head->next;

	if(node == NULL)
		return;

	head->next = node->next;   
	free(node);
	delaltRec(head->next);  
}

void deletelist(struct node** head)
{
	struct node* rider = *head;
	struct node* next_node;
	while(rider != NULL) 
	{
		next_node = rider->next;
		free(rider);
		rider = next_node;
	}
	*head = NULL;
}

void delNode(struct node* node_ptr)   
{
	struct node* temp = node_ptr->next;
	node_ptr->data = temp->data;
	node_ptr->next = temp->next;
	free(temp);
}

void delposition(struct node** head, int position)
{
	if((*head) == NULL)
		return;

	if(position == 0)
	{
		free(*head);
		*head = NULL;               
		return;
	}

	int i;
	struct node* rider = *head;
	for(i = 0; rider != NULL && i < position - 1; i++)
		rider = rider->next;
	struct node* temp = rider->next;
	rider->next = temp->next;
	free(temp);
}

void delLastOcc(struct node* head, int key)
{
    struct node* rider = head;
    struct node* ptr = NULL;
	while(rider != NULL) 
	{
		if(rider->data == key) 
			ptr = rider;        
		rider = rider->next;
	}

	if(ptr != NULL && ptr->next == NULL) 
	{
		rider = head;
		while(rider->next != ptr) 
			rider = rider->next;       
		rider->next = NULL;
	}

	if(ptr != NULL && ptr->next != NULL) 
	{
		ptr->data = ptr->next->data;
		rider = ptr->next;
		ptr->next = ptr->next->next;
		free(rider);
	}
}

void skipMdeleteN(struct node* head, int m, int n)
{
	struct node* d;
	int count;

	while(head != NULL)
	{
		for(count = 1; count < m && head != NULL; count++)
			head = head->next;

		if(head == NULL)
			return;

		d = head->next;
		for(count = 1; count <= n && d != NULL; count++)
		{
			struct node *temp = d;
			d = d->next;
			free(temp);
		}
		head->next = d; 
		head = d;
	}
}

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void display(struct node* head)
{
	while(head != NULL)
	{
		printf("-->%d", head->data);
		head = head->next;
	}     
}

int count(struct node* head)
{
	int ncount = 0;
	while(head != NULL)
	{
		ncount++;
		head = head->next;
	} 
	return ncount;    
}

int countRec(struct node* head)
{
	if(head == NULL)
		return 0;

	return 1 + countRec(head->next);
}

int lengthEvenOdd(struct node* head)
{
	while(head != NULL && head->next != NULL)
	{
		head = head->next->next;
	}
	if(head == NULL)
		return 1;
	else
		return 0;
}

int search(struct node* head, int x)
{
	while(head != NULL)
	{
		if(head->data == x)
			return 1;
		head = head->next;
	}
	return 0;
} 

int searchRec(struct node* head, int x)
{
	if(head == NULL)
		return 0;

	if(head->data == x)
		return 1;

	return searchRec(head->next, x);
} 

void modify(int old_value, int new_value, struct node* head)
{
	while(head->data != old_value && head != NULL)
		head = head->next;
	if(head == NULL)
		printf("The inputted value not found in the list");
	else
		head->data = new_value;      
}

void printReverse(struct node* rider)
{
	if(rider == NULL)
		return;
	printReverse(rider->next);
	printf("--->%d", rider->data);
}

void reverse(struct node** head)
{
	struct node* rider = *head;
	struct node* prev = NULL;
	struct node* r_next;
	while(rider != NULL)
	{
		r_next = rider->next;
		rider->next = prev;
		prev = rider;
		rider = r_next;
	}
	*head = prev;
}

void reverseRec(struct node** head)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
		
	struct node* first = *head;
	struct node* rest = first->next; 
	
	reverseRec(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

struct node* revk(struct node* head, int k)
{
	struct node* rider = head;
	struct node* temp;
	struct node* prev = NULL;
	int count = 0;   
	while(rider != NULL && count < k)
	{
		temp = rider->next;
		rider->next = prev;
		prev = rider;
		rider = temp;
		count++;
	}
	if(rider != NULL)
		head->next = revk(rider, k);
	return prev;
} 

struct node *revkalt(struct node* head, int k)
{
	struct node* rider = head;
	struct node* temp;
	struct node* prev = NULL;
	int count = 0;   
	while(rider != NULL && count < k)
	{
		temp = rider->next;
		rider->next = prev;
		prev = rider;
		rider = temp;
		count++;
	}
	if(head != NULL)
		head->next = rider;   
	count = 0;
	while(count < k-1 && rider != NULL)
	{
		rider = rider->next;
		count++;
	}
	if(rider != NULL)
		rider->next = revkalt(rider->next, k); 
	return prev;
}

void removedupsort(struct node* head)
{
	if(head == NULL)
		return;
		
	struct node* dup;
	while(head->next != NULL) 
	{
		if(head->data == head->next->data) 
		{
			dup = head->next;
			head->next = dup->next;
			free(dup);  
		}
		else 
			head = head->next; 
	}
}

struct node* removedupsortRec(struct node* head)
{
	if(head == NULL)
		return NULL;
		
	head->next = removedupsortRec(head->next);
	
	if(head->next != NULL && head->data == head->next->data) 
	{
		struct node* dup = head->next;
		head->next = dup->next;
		free(dup);
		return head;  
	}
	return head;
}

void removedupunsort(struct node* head)
{
	unordered_set<int> seen;

	struct node *prev;
	while(head != NULL)
	{
		if(seen.find(head->data) != seen.end())
		{
			prev->next = head->next;
			free(head);
		}
		else
		{
			seen.insert(head->data);
			prev = head;
		}
		head = prev->next;
	}
}

void AlternateSplit(struct node* head, struct node** first, struct node** second)
{
	*first = newNode(0);
	*second = newNode(0);

	struct node *frider = *first;
	struct node *srider = *second;

	while(head != NULL)
	{
		frider->next = head;
		frider = frider->next;
		head = head->next;

		if(head)
		{
			srider->next = head;
			srider = srider->next;
			head = head->next;
		}
	}

	frider->next = NULL;
	srider->next = NULL;
	*first = (*first)->next;
	*second = (*second)->next;
}

void sort012(struct node* head)
{
	struct node* rider = head;
	int count[3] = {0, 0, 0};  
	int i = 0;
	while(rider != NULL)
	{
		count[rider->data]++;
		rider = rider->next;
	}
	rider = head;
	while(rider != NULL)
	{
		if(count[i] == 0)
			i++;
		else
		{
			rider->data = i;
			count[i]--;
			rider = rider->next;
		}
	}
}       

void sort_actual(struct node** head)
{
	struct node* prev = *head;
	struct node* curr = (*head)->next;
	while(curr != NULL)
	{
		if(curr->data < prev->data)
		{
			prev->next = curr->next;
			curr->next = *head;
			*head = curr;
			curr = prev;
		}
		else
			prev = curr;
		curr = curr->next;

	}
} 

void sorted_insert1(struct node **sorted, struct node *temp)
{
	struct node *rider = *sorted;
	if(rider == NULL || temp->data <= rider->data)
	{
		temp->next = rider;
		(*sorted) = temp;
	}
	else
	{
		while(rider->next != NULL && temp->data > rider->next->data)
			rider = rider->next;
		temp->next = rider->next;
		rider->next = temp;
	}
}
void insertion_sort(struct node** head)
{
	struct node *sorted = NULL;
	struct node* rider = *head;
	while (rider != NULL)
	{
		struct node *next = rider->next;
		sorted_insert1(&sorted, rider);
		rider = next;
	}
	*head = sorted;
}

void FrontBackSplit(struct node* head, struct node** first, struct node** second)
{
    struct node* slowptr = head;
	struct node* fastptr = head;
	while(fastptr->next != NULL && fastptr->next->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	
    *first = head;
    *second = slowptr->next;
    slowptr->next = NULL;
}
struct node *mergeSortedLists(struct node *a, struct node *b) 
{
	if(a == NULL) 
		return b;

	if(b == NULL) 
		return a;

	if(a->data <= b->data) 
	{
		a->next = mergeSortedLists(a->next, b);
		return a;
	}
	else
	{
		b->next = mergeSortedLists(a, b->next);
		return b;
	}
} 
void merge_sort(struct node** head)
{
	struct node* a;
	struct node* b;
 
	if((*head) == NULL || (*head)->next == NULL)
		return;

	FrontBackSplit(*head, &a, &b); 
 
	merge_sort(&a);
	merge_sort(&b);
 
	*head = mergeSortedLists(a, b);
}

void sortAscendDescendList(struct node** head)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
		
	struct node *Ahead, *Dhead;
	AlternateSplit(*head, &Ahead, &Dhead);
	reverse(&Dhead);
	*head = mergeSortedLists(Ahead, Dhead);
}

int getnth(struct node* head, int n)
{
	int count = 0; // 0 indexed
	while(head != NULL)
	{
		if(count == n)
			return head->data;
		count++;
		head = head->next;
	}
} 

int printmid(struct node* head)
{
	if(head == NULL)
		return -1;

	struct node* slowptr = head;
	struct node* fastptr = head;
	while(fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	return slowptr->data;
}  

int printnthfromend(struct node* head, int n)
{
	if(head == NULL)
		return -1;
		
	struct node* slowptr = head;
	struct node* fastptr = head;

	for(int i = 1; i <= n - 1; i ++)
		fastptr = fastptr->next;

	while(fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}	
	return slowptr->data;
}

int dupcount(struct node* head, int n)
{
	int count = 0;
	while(head != NULL)
	{
		if(head->data == n)
			count++;
		head = head->next;
	}
	return count;
}  

int detectloop(struct node* head)
{
	struct node* slowptr = head;
	struct node* fastptr = head;
	while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if(slowptr == fastptr)
			return 1;
	}
	return 0;
} 

void detectandRemoveloop(struct node* head)
{
	struct node* slowptr = head;
	struct node* fastptr = head;
	while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if(slowptr == fastptr)
			break;
	}

	if(slowptr == fastptr)
	{
		slowptr = head;
		while(slowptr->next != fastptr->next)
		{
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}
		fastptr->next = NULL;
	}
}    

int countNodesLoopUtil(struct node* head)
{
	int count = 1;
	struct node* rider = head;
	while(rider->next != head)
	{
		count++;
		rider = rider->next;	
	}
	return count;
}
int countNodesLoop(struct node* head)
{
	struct node* slowptr = head;
	struct node* fastptr = head;
	while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if(slowptr == fastptr)
			return countNodesLoopUtil(slowptr);
	}
	return 0;
}

int decimalValue(struct node* head)
{
	int res = 0;
	while(head != NULL)
	{
		res = (res << 1) + head->data;
		head = head->next;	
	}	
	return res;
}

void swap(struct node** a, struct node** b)
{
	printf("\n%d %d\n", (*a)->data, (*b)->data);
	struct node* temp = *a;
	*a = *b;
	*b = temp;
}
void swapNodes(struct node** head, int x, int y)
{	
	if(x == y) 
		return;

	struct node* rider = *head;
	struct node* a = NULL;
	struct node* b = NULL;
	
	while(rider != NULL)
	{
		if(rider->data == x)
			a = rider;
		else if(rider->data == y)
			b = rider;
		rider = rider->next;
	}
	
	if(a != NULL && b != NULL)
	{
		swap(a, b);
		//display(*head);
		swap(&(a->next), &(b->next));
	}
}
   
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void pairwiseSwap(struct node *head)
{
	while(head != NULL && head->next != NULL)
	{
		swap(&head->data, &head->next->data);
		head = head->next->next;
	}
}

void pairwiseSwapRec(struct node* head)
{
	if(head != NULL && head->next != NULL)
	{
		swap(&head->data, &head->next->data);
		pairwiseSwapRec(head->next->next);
	}  
}

void addOneUtil(struct node *head)
{
	struct node* res = head;
	struct node *temp;

	int carry = 1, sum;

	while(head != NULL) 
	{
		sum = carry + head->data;
		carry = (sum >= 10)? 1 : 0;
		sum = sum % 10;
		head->data = sum;
		temp = head;
		head = head->next;
	}

	if(carry > 0)
		temp->next = newNode(carry);
		
}
void addOne(struct node** head)
{
	reverse(head);
	addOneUtil(*head);
	reverse(head);
}

int addWithCarry(struct node *head)
{
	if(head == NULL)
		return 1;

	int res = head->data + addWithCarry(head->next);

	head->data = res % 10;
	return (res / 10);
} 
void addOneRec(struct node** head)
{
	int carry = addWithCarry(*head);
	if(carry)
	{
		struct node *temp = newNode(carry);
		temp->next = *head;
		*head = temp;
	}
} 

void zigZag(struct node* head)
{
	int flag = 1; // 1 for < and 0 for >

	while(head->next != NULL)
	{
		if(flag)  
		{
			if (head->data > head->next->data)
				swap(&head->data, &head->next->data);
		}
		else 
		{
			if(head->data < head->next->data)
				swap(&head->data, &head->next->data);
		}
		head = head->next;
		flag = !flag; 
	}
}

void rearrangeEvenOdd(struct node* head)
{
	if(head == NULL)
		return;

	struct node* odd = head;
	struct node* even = head->next;
	struct node* evenFirst = even;
	struct node* temp;

	while(odd != NULL && even != NULL)
	{
		temp = even->next;
		if(temp == NULL) //no nodes 
			break;
		
		odd->next = even->next;
		odd = odd->next;
		
		even->next = odd->next;
		even = even->next;
	}
	
	odd->next = evenFirst;
}

void moveLastToFront(struct node** head)
{
	if(*head == NULL || (*head)->next == NULL)
		return;

	struct node* secLast;
	struct node* last = *head;

	while(last->next != NULL)
	{
		secLast = last;
		last = last->next;
	}

	secLast->next = NULL;
	last->next = *head;
	*head = last;
}

void moveMiddleToFront(struct node** head)
{
	if(*head == NULL || (*head)->next == NULL) 
		return;

	struct node* slowptr = *head;
	struct node* fastptr = *head;
	struct node* prev = NULL;
	while(fastptr != NULL && fastptr->next != NULL)
	{
		prev = slowptr;
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}

	prev->next = slowptr->next;
	slowptr->next = *head;
	*head = slowptr;
}

void moveFirstToLast(struct node** head)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
		
	struct node* first = *head;
	*head = (*head)->next;
	
	struct node* last = *head;
	while(last->next != NULL)
		last = last->next;
	
	last->next = first;
	first->next = NULL;
}

int countRotations(struct node* head)
{
	if(head == NULL || head->next == NULL)
		return 0;

	int k = 0;	
	int num = head->data;

	while(head->next != NULL)
	{
		if(num > head->data)
			break;
		k++;
		head = head->next;
	}
	return k;
}

int sum_last_Nnodes(struct node* head, int n)
{
	struct node* rider1 = head;
	struct node* rider2 = head;
	
	int sum1 = 0, sum2 = 0;
	
	while(rider1 != NULL && n--)
	{
		sum1 += rider1->data;
		rider1 = rider1->next;
	}
	
	while(rider1 != NULL)
	{
		sum1 += rider1->data;
		sum2 += rider2->data;
		
		rider1 = rider1->next;
		rider2 = rider2->next;
	}
	
	return (sum1 - sum2);
}

int isSorted(struct node* head)
{
	if(head == NULL)
		return 1;
		
	while(head->next != NULL)
	{
		if(head->data > head->next->data)
			return 0;
		head = head->next;
	}
	
	return 1;
}

int isSortedRec(struct node* head)
{
	if(head == NULL || head->next == NULL)
		return 1;
		
	return (head->data <= head->next->data && isSortedRec(head->next));
}

int identical(struct node *a, struct node *b)
{
    while(1)
    {
    	if(a == NULL && b == NULL)
            return 1;
        if(a == NULL && b != NULL)
            return 0; 
        if(a != NULL && b == NULL)
            return 0; 
        if(a->data != b->data)
            return 0; 
        a = a->next;
        b = b->next; 
    }          
}   
int isPalindrome(struct node* head)
{
	if(head == NULL || head->next == NULL)
		return 0;

	struct node* slowptr = head;
	struct node* fastptr = head;
	struct node* prev_slowptr;
	struct node* mid_node = NULL;
	
	while(fastptr != NULL && fastptr->next != NULL)
	{
		prev_slowptr = slowptr;
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	
	if(fastptr != NULL) //odd
	{
		mid_node = slowptr;
		slowptr = slowptr->next;
	}
		
	prev_slowptr->next = NULL;
	struct node* a = head;
	struct node* b = slowptr;
	
	reverse(&b);
	int result = identical(a, b);
	reverse(&b);
	
	if(mid_node != NULL)
	{
		prev_slowptr->next = mid_node;
		mid_node->next = b;
	}
	else
		prev_slowptr->next = b;
	
	return result;
}



int main()
{
	int n, oldv, newv, index, nend, n1, k, kalt, key, position, x, y, M, N;
	struct node* res;
	struct node* res1;
	struct node* first, *second;

	struct node* i = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &i->data);
	i->next = NULL;
	struct node* head = i;
	
	while(1)
	{
		printf("\n\n LIST OF OPERATIONS");
		printf("\n 1.Insertion at the front");
		printf("\n 2.Insertion at the end");
		printf("\n 3.Insertion in the middle");
		printf("\n 4.Insertion in a sorted way");
		printf("\n 5.Insertion in middle");
		printf("\n 6.Insertion in nth position from last node");
		printf("\n 7.Deletion at the front");
		printf("\n 8.Deletion at the end");
		printf("\n 9.Deletion in the middle");
		printf("\n 10.Deletion of middle node");
		printf("\n 11.Deletion of alternate nodes");
		printf("\n 12.Deletion of alternate nodes Recursive");
		printf("\n 13.Delete entire list");
		printf("\n 14.Delete given pointer to a node");
		printf("\n 15.Delete at a given position");
		printf("\n 16.Delete last occurence of an item");
		printf("\n 17.Delete n nodes after m nodes");
		printf("\n 19.Count");
		printf("\n 20.Count Recursive");
		printf("\n 21.Length even or odd");
		printf("\n 22.Search");
		printf("\n 23.Search Recursive");
		printf("\n 24.Modify");
		printf("\n 25.Print Reverse");
		printf("\n 26.Reverse");
		printf("\n 27.Reverse Recursive");
		printf("\n 28.Reverse by k nodes");
		printf("\n 29.Reverse by k nodes alternately");
		printf("\n 30.Remove duplicates(sorted)");
		printf("\n 31.Remove duplicates(sorted) Recursive");
		printf("\n 32.Remove duplicates(unsorted)");
		printf("\n 33.Alternatively split a list");
		printf("\n 34.Sort 0s,1s,2s");
		printf("\n 35.Sort 0s,1s,2s by changing links");
		printf("\n 36.Sort by actual values(absoulte sorted)");
		printf("\n 37.Insertion sort");
		printf("\n 38.Merge sort");
		printf("\n 39.Quick sort");
		printf("\n 40.Sort a list that is sorted alternating ascending and descending orders");
		printf("\n 41.Get nth node");
		printf("\n 42.Print middle");
		printf("\n 43.Print nth node from end");
		printf("\n 44.Number of times a node has occurred");
		printf("\n 45.Detect a loop(insert 5 nodes)");
		printf("\n 46.Detect and remove loop");
		printf("\n 47.No of nodes in loop");
		printf("\n 48.Decimal Equivalent");
		printf("\n 49.Swap nodes without swapping data");
		printf("\n 50.Pairwise Swap");
		printf("\n 51.Pairwise Swap Recursive");
		printf("\n 52.Add one");
		printf("\n 53.Add one Recursive");
		printf("\n 54.ZigZag a < b > c < d > ..");
		printf("\n 55.Rearrange odd and even positioned nodes together");
		printf("\n 56.Move last node to front");
		printf("\n 57.Move middle node to front");
		printf("\n 58.Move first node to last");
		printf("\n 59.Count Rotations");
		printf("\n 60.Sum of last two nodes");
		printf("\n 61.Check if list is sorted");
		printf("\n 62.Check if list is sorted Recursive");
		printf("\n 63.Check if list is palindrome");
		printf("\n 64.Exit");
		printf("\n Enter the choice:");
		scanf("%d", &n);
		switch(n)
		{
			case 1: addatbeg(&head);
					display(head);
					break;
			case 2: addatend(&head);
					display(head);
					break;
			case 3: addatmid(head);
					display(head);
					break;
			case 4: sorted_insert(&head);
					display(head);
					break;
			case 5: scanf("%d", &n);
					insert_middle(head);
					display(head);
					break;
			case 6: scanf("%d", &n);
					insert_nth_from_last(head, n);
					display(head);
					break;
			case 7: delatbeg(&head);
					display(head);
					break;
			case 8: delatend(&head);
					display(head);
					break;
			case 9: delatmid(head);
					display(head);
					break;
			case 10: delMidNode(&head);
					 display(head);
					 break;
			case 11: delalt(head);
					 display(head);
					 break;
			case 12: delaltRec(head);
					 display(head);
					 break;
			case 13: deletelist(&head);
					 display(head);
					 break;
			case 14: delNode(head->next->next);
					 display(head);
					 break;
			case 15: printf("\n Enter the position: ");
					 scanf("%d", &position);
					 delposition(&head, position);
					 display(head);
					 break;
			case 16: printf("\n Enter the key: ");
					 scanf("%d", &key);
					 delLastOcc(head, key);
					 display(head);
					 break;
			case 17: printf("\n Enter m and n: ");
					 scanf("%d%d", &M, &N);
					 skipMdeleteN(head, M, N);
					 display(head);
					 break;
			case 19: printf("\n No. of nodes: %d",count(head));
					 break;
			case 20: printf("\n No. of nodes: %d",countRec(head));
				 	 break;
			case 21: if(lengthEvenOdd(head))
						printf("Even length");
					 else
					 	printf("Odd length");
					 break;
			case 22: printf("\n Enter the element to be searched for:");
					 scanf("%d", &x);
					 if(search(head, x))
						printf("\n Found");
					 else
						printf("\n Not found");
					 break;
			case 23: printf("\n Enter the element to be searched for:");
					 scanf("%d", &x);
					 if(searchRec(head, x))
						printf("\n Found");
					 else
						printf("\n Not found");
					 break;
			case 24: printf("\n Enter the value to be replaced:");
					 scanf("%d", &oldv);
					 printf("\n Enter the new value:");
					 scanf("%d", &newv);
					 modify(oldv, newv, head);
					 display(head);
					 break;
			case 25: printReverse(head);
				 	 break;
			case 26: reverse(&head);
					 display(head);
				 	 break;
			case 27: reverseRec(&head);
				 	 display(head);
				 	 break;
			case 28: printf("\n Enter the factor: ");
					 scanf("%d", &k);
					 head = revk(head, k);
					 display(head);
					 break;
			case 29: printf("\n Enter the factor: ");
					 scanf("%d", &kalt);
					 head = revkalt(head, kalt);
					 display(head);
					 break;
			case 30: removedupsort(head);
				 	 display(head);
				   	 break;
			case 31: head = removedupsortRec(head);
					 display(head);
					 break;
			case 32: removedupunsort(head);
				 	 display(head);
				 	 break;
			case 33: AlternateSplit(head, &first, &second);
					 display(first);
					 printf("\n");
					 display(second);
					 break;
			case 34: sort012(head);
					 display(head);
					 break;
			case 36: sort_actual(&head);
					 display(head);
					 break;
			case 37: insertion_sort(&head);
					 display(head);
					 break;
			case 38: merge_sort(&head);
					 display(head);
					 break;
			case 40: sortAscendDescendList(&head);
					 display(head);
					 break;
			case 41: printf("\n Enter the index: ");
				 	 scanf("%d", &index);
				 	 printf("\n The node at %d position is %d", index, getnth(head, index));
				 	 break;
			case 42: printf("\n The middle node is %d", printmid(head));
					 break;
			case 43: printf("\n Enter the index: ");
					 scanf("%d", &index);
					 printf("\n The %dth node from end is %d", index, printnthfromend(head, index));
				 	 break;
			case 44: printf("\n Enter a number: ");
					 scanf("%d", &n);
					 printf("\n %d has occurred %d times", n, dupcount(head, n));
				 	 break;
			case 45: head->next->next->next->next = head->next;
					 if(detectloop(head))
					 	printf("Loop is detected");
				 	 break;
			case 46: head->next->next->next->next = head->next;
					 //display(start);
					 detectandRemoveloop(head);
					 display(head);
					 break;
			case 47: head->next->next->next->next = head->next;
					 printf("%d", countNodesLoop(head));
					 break;
			case 48: printf("%d", decimalValue(head));
					 break;
			case 49: printf("\n Enter the nodes to be swapped: ");
					 scanf("%d%d", &x, &y);
					 swapNodes(&head, x, y);
					 display(head);
					 break;
			case 50: pairwiseSwap(head);
					 display(head);
					 break;
			case 51: pairwiseSwapRec(head);
					 display(head);
				 	 break;
			case 52: addOne(&head);
					 display(head);
					 break;
			case 53: addOneRec(&head);
					 display(head);
					 break;
			case 54: zigZag(head);
					 display(head);
					 break;
			case 55: rearrangeEvenOdd(head);
					 display(head);
					 break;
			case 56: moveLastToFront(&head);
					 display(head);
					 break;
			case 57: moveMiddleToFront(&head);
					 display(head);
					 break;
			case 58: moveFirstToLast(&head);
					 display(head);
					 break;
			case 59: printf("%d",countRotations(head));
					 break;
			case 60: scanf("%d", &n);
					 printf("%d", sum_last_Nnodes(head, n));
					 break;
			case 61: if(isSorted(head))
					 	printf("List is sorted");
					 else
					 	printf("Not sorted");
					 break;
			case 62: if(isSortedRec(head))
					 	printf("List is sorted");
					 else
					 	printf("Not sorted");
					 break;
			case 63: if(isPalindrome(head))
					 	printf("List is Palindrome");
					 else
					 	printf("Not palindrome");
					 break;			 
			case 64: goto exit;
		}
	}
	exit:
	return 0;
}                                                                    

