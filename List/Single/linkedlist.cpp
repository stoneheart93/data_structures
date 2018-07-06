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

}*start, *rest;

void addatbeg()
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted at beginning: ");
	scanf("%d", &temp->data);
	temp->next = start;
	start = temp;
}

void addatend(struct node* rider)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted at end: ");
	scanf("%d", &temp->data);  
    while(rider->next != NULL)
        rider = rider->next;  
	temp->next = NULL;
    rider->next = temp;
}

void addatmid(struct node* rider)
{
    int num;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted at middle: ");
    scanf("%d", &temp->data);
    printf("Enter the data succeeding the number to be inserted: ");
    scanf("%d", &num);
    while(rider->next->data != num)
        rider = rider->next;
    temp->next = rider->next;
    rider->next = temp;
}

void sorted_insert(struct node* rider)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted in sorted way: ");
    scanf("%d", &temp->data);
    if(rider == NULL || temp->data <= rider->data)
    {
        temp->next = rider;
    	start = temp;
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
    
    while(fastptr->next != NULL && fastptr->next->next != NULL)
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

void delatbeg()
{
    struct node* temp = start;
    start = start->next;
    free(temp);
}

void delatend(struct node* rider)
{
	struct node* temp;
	if(rider->next == NULL)
	{
		temp = rider;
		free(temp);
		start = NULL;
	}
	else
	{
		while(rider->next->next != NULL)         
            rider=rider->next;
     	temp = rider->next;
     	rider->next = NULL;
     	free(temp);
    }
}

void delatmid(struct node* rider)
{
    int num;
    struct node* temp;
	printf("Enter the number to be deleted: ");
    scanf("%d", &num);
    while(rider->next->data != num)
        rider = rider->next;
    temp = rider->next;
    rider->next = temp->next;
    free(temp);
}   
 
void delalt(struct node* rider)
{
    if(rider == NULL)
        return;
    struct node* prev = rider; 
    struct node* node = rider->next;
    while(prev != NULL && node != NULL)
    {
        prev->next = node->next;   
        free(node);
        prev = prev->next;
        if(prev != NULL)
            node = prev->next;
    }      
}

void delaltRec(struct node* rider)
{
    if(rider == NULL)
        return;
    
	struct node* node = rider->next;
    
    if(node == NULL)
    	return;
    
	rider->next = node->next;   
    free(node);
    delaltRec(rider->next);  
}


void deletelist(struct node* rider)
{
    struct node* next_node;
    while(rider != NULL) 
    {
		next_node = rider->next;
        free(rider);
        rider = next_node;
    }
    start = NULL;
}

void delNode(struct node* node_ptr)   
{
	struct node* temp = node_ptr->next;
   	node_ptr->data = temp->data;
   	node_ptr->next = temp->next;
   	free(temp);
}

void delposition(struct node* rider, int position)
{
	if(rider == NULL)
    	return;
 
	struct node* temp; 
    if(position == 0)
    {
        temp = start;
		start = start->next;   
        free(temp);               
        return;
    }
    
	int i;
	for(i = 0; rider != NULL && i < position - 1; i++)
        rider = rider->next;
    if(rider == NULL || rider->next == NULL)
        return;
    temp = rider->next;
    rider->next = temp->next;
    free(temp);
}

void delLastOcc(struct node* rider, int key)
{
	struct node *temp = rider, *ptr = NULL;
    while(temp != NULL) 
	{
        if(temp->data == key) 
        	ptr = temp;        
        temp = temp->next;
    }
 
    if(ptr != NULL && ptr->next == NULL) 
	{
        temp = rider;
        while(temp->next != ptr) 
            temp = temp->next;       
        temp->next = NULL;
    }
 
    if(ptr != NULL && ptr->next != NULL) 
	{
        ptr->data = ptr->next->data;
        temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }
}

void skipMdeleteN(struct node* rider, int m, int n)
{
	struct node* d;
    int count;
 
    while(rider != NULL)
    {
        for(count = 1; count < m && rider != NULL; count++)
            rider = rider->next;
 
        if(rider == NULL)
        	return;
 
        d = rider->next;
        for(count = 1; count <= n && d != NULL; count++)
        {
            struct node *temp = d;
            d = d->next;
            free(temp);
        }
        rider->next = d; 
        rider = d;
    }
}

void display(struct node* rider)
{
 	while(rider != NULL)
	{
	    printf("-->%d", rider->data);
	    rider = rider->next;
    }     
}

int count(struct node* rider)
{
 	int ncount = 0;
    while(rider != NULL)
	{
    	ncount++;
	    rider = rider->next;
    } 
    return ncount;    
}

int countRec(struct node* rider)
{
    if(rider == NULL)
    	return 0;
 
    return 1 + countRec(rider->next);
}

int search(struct node* rider, int x)
{
    while(rider != NULL)
    {
        if(rider->data == x)
        	return 1;
        rider = rider->next;
    }
    return 0;
} 
 
int searchRec(struct node* rider, int x)
{
    if(rider == NULL)
    	return 0;
     
    if(rider->data == x)
    	return 1;
    	
    return searchRec(rider->next, x);
} 

void modify(int old_value, int new_value, struct node* rider)
{
    while(rider->data != old_value && rider != NULL)
        rider=rider->next;
    if(rider==NULL)
        printf("The inputted value not found in the list");
    else
        rider->data = new_value;      
}

void printReverse(struct node* rider)
{
    if(rider == NULL)
       return;
	printReverse(rider->next);
	printf("--->%d", rider->data);
}

void reverse(struct node* rider)
{
    struct node* prev = NULL;
    struct node* temp;
    while(rider != NULL)
    {
        temp = rider->next;
        rider->next = prev;
        prev = rider;
    	rider = temp;
	}
    start = prev;
}

void reverseRec(struct node* first)
{
    if(first == NULL|| first->next == NULL)
        return;
    rest = first->next;
    reverseRec(rest);
    first->next->next = first;
    first->next = NULL;
    start = rest;
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

void removedupsort(struct node* rider)
{
    if(rider == NULL)
        return;
    struct node* dup; 
    while(rider->next != NULL) 
    {
        if(rider->data == rider->next->data) 
        {
            dup = rider->next;
            rider->next = dup->next;
			free(dup);  
        }
        else 
            rider = rider->next; 
    }
}

void removedupunsort(struct node* rider)
{
	unordered_set<int> seen;
 
    struct node *prev;
    while(rider != NULL)
    {
        if(seen.find(rider->data) != seen.end())
        {
            prev->next = rider->next;
        	free(rider);
        }
        else
        {
           seen.insert(rider->data);
           prev = rider;
        }
        rider = prev->next;
    }
}

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void splitList(struct node *rider, struct node **first, struct node **second)
{
    *first = newNode(0);
    *second = newNode(0);
 
    struct node *frider = *first;
    struct node *srider = *second;
    
    while(rider != NULL)
    {
        frider->next = rider;
        frider = frider->next;
        rider = rider->next;
 
        if(rider)
        {
            srider->next = rider;
            srider = srider->next;
            rider = rider->next;
        }
    }
 
    frider->next = NULL;
    srider->next = NULL;
    *first = (*first)->next;
    *second = (*second)->next;
}

void sort012(struct node* rider)
{
    int count[3] = {0, 0, 0};  
    int i = 0;
    while(rider != NULL)
    {
        count[rider->data]++;
        rider = rider->next;
    }
    rider = start;
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

void sort_actual(struct node* rider)
{
	struct node* prev = rider;
	struct node* curr = rider->next;
	while(curr != NULL)
	{
		if(curr->data < prev->data)
		{
			prev->next = curr->next;
			curr->next = start;
			start = curr;
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
void insertion_sort(struct node* rider)
{
	struct node *sorted = NULL;
	while (rider != NULL)
    {
    	struct node *next = rider->next;
        sorted_insert1(&sorted, rider);
        rider = next;
    }
    start = sorted;
}

void reverse1(struct node** Dhead)
{
	struct node* rider = (*Dhead);
    struct node* prev = NULL;
    struct node* temp;
    while(rider != NULL)
    {
        temp = rider->next;
        rider->next = prev;
        prev = rider;
    	rider = temp;
	}
    (*Dhead) = prev;
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
void sortAscendDescendList(struct node *head)
{
    struct node *Ahead, *Dhead;
    splitList(head, &Ahead, &Dhead);
    reverse1(&Dhead);
    start = mergeSortedLists(Ahead, Dhead);
}

int getnth(struct node* rider, int n)
{
    int count = 0; // 0 indexed
    while(rider != NULL)
    {
        if(count == n)
            return rider->data;
        count++;
        rider = rider->next;
    }
} 
                   
int printmid(struct node* rider)
{
    struct node* slowptr = rider;
    struct node* fastptr = rider;
    while(fastptr->next != NULL && fastptr->next->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return slowptr->data;
}  

int printnthfromend(struct node* rider, int n)
{
    int count = 0, i;
    while(rider != NULL)
    {
        rider = rider->next;
        count++;
    }
    rider = start;
    for(i = 1; i < count - n + 1; i++)
        rider = rider->next;
    return rider->data;
}

int dupcount(struct node* rider, int n)
{
    int count = 0;
    while(rider != NULL)
    {
        if(rider->data == n)
            count++;
        rider = rider->next;
    }
    return count;
}  

int detectloop(struct node* rider)
{
    struct node* slowptr = rider;
    struct node* fastptr = rider;
    while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr)
        	return 1;
    }
    return 0;
}    

void detectandRemoveloop(struct node* rider)
{
    struct node* slowptr = rider;
    struct node* fastptr = rider->next;
    while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr)
        	break;
    }
    
    if(slowptr == fastptr)
    {
    	slowptr = rider;
    	while(slowptr != fastptr->next)
    	{
      		slowptr = slowptr->next;
        	fastptr = fastptr->next;
		}
		fastptr->next = NULL;
	}
}    

int decimalValue(struct node* rider)
{
	int res = 0;
	while(rider != NULL)
	{
		res = (res << 1) + rider->data;
		rider = rider->next;	
	}	
	return res;
}

void swapNodes(struct node *start, int x, int y)
{	
	if(x == y) 
		return;
 
	struct node *prevX;
	struct node *currX = start;
	while(currX && currX->data != x)
	{
    	prevX = currX;
    	currX = currX->next;
	}
 
	struct node *prevY;
	struct node *currY = start;
	while(currY && currY->data != y)
	{
    	prevY = currY;
    	currY = currY->next;
	}
 
	if(currX == NULL || currY == NULL)
    	return;
 
   	if(prevX != NULL)
    	prevX->next = currY;
	else 
    	start = currY;  
 
	if(prevY != NULL)
    	prevY->next = currX;
	else  
       start = currX;
 
	struct node *temp = currY->next;
	currY->next = currX->next;
	currX->next  = temp;
}


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void pairwiseSwap(struct node *rider)
{
    while(rider != NULL && rider->next != NULL)
    {
        swap(&rider->data, &rider->next->data);
		rider = rider->next->next;
    }
}

void pairwiseSwapRec(struct node* rider)
{
	if(rider != NULL && rider->next != NULL)
  	{
    	swap(&rider->data, &rider->next->data);
    	pairwiseSwapRec(rider->next->next);
  	}  
}

int addWithCarry(struct node *rider)
{
    if(rider == NULL)
    	return 1;
 
    int res = rider->data + addWithCarry(rider->next);

    rider->data = res % 10;
    return (res / 10);
} 
void addOneRec(struct node *rider)
{
    int carry = addWithCarry(rider);
	if(carry)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = carry;
        temp->next = rider;
        start = temp;
    }
} 

struct node *addOneUtil(struct node *rider)
{
	struct node* res = rider;
    struct node *temp, *prev = NULL;
 
    int carry = 1, sum;
 
    while(rider != NULL) 
    {
        sum = carry + rider->data;
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        rider->data = sum;
        temp = rider;
        rider = rider->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);
 
    return res;
}
void addOne(struct node *rider)
{
    reverse(rider);
    rider = addOneUtil(start);
    reverse(rider);
}

void zigZag(struct node *rider)
{
    int flag = 1; // 1 for < and 0 for >
 
	while(rider->next != NULL)
    {
        if(flag)  
        {
            if (rider->data > rider->next->data)
                swap(&rider->data, &rider->next->data);
        }
        else 
        {
	        if(rider->data < rider->next->data)
        		swap(&rider->data, &rider->next->data);
        }
		rider = rider->next;
        flag = !flag; 
	}
}

void rearrangeEvenOdd(struct node *rider)
{
    if(rider == NULL)
    	return;
 
	struct node *odd = rider;
    struct node *even = rider->next;
    struct node *evenFirst = even;
 
    while (1)
    {
        if (!odd || !even || !(even->next))
        {
            odd->next = evenFirst;
            break;
        }
 	
	    odd->next = even->next;
        odd = even->next;
 	
	    if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenFirst;
            break;
        }
 
        even->next = odd->next;
        even = odd->next;
    }
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
	if(*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL) //till two nodes, functionality cant be applied 
		return;
		
	struct node* slowptr = *head;
    struct node* fastptr = *head;
    struct node* prev = NULL;
	while(fastptr->next != NULL && fastptr->next->next != NULL)
    {
    	prev = slowptr;
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    
    prev->next = slowptr->next;
    slowptr->next = *head;
    *head = slowptr;
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
    start = i;
    
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
        printf("\n 10.Deletion of alternate nodes");
        printf("\n 11.Deletion of alternate nodes Recursive");
        printf("\n 12.Delete entire list");
        printf("\n 13.Delete given pointer to a node");
        printf("\n 14.Delete at a given position");
        printf("\n 15.Delete last occurence of an item");
        printf("\n 16.Delete n nodes after m nodes");
        printf("\n 17.Count");
        printf("\n 18.Count Recursive");
        printf("\n 19.Search");
        printf("\n 20.Search Recursive");
        printf("\n 21.Modify");
        printf("\n 22.Print Reverse");
        printf("\n 23.Reverse");
        printf("\n 24.Reverse Recursive");
        printf("\n 25.Reverse by k nodes");
        printf("\n 26.Reverse by k nodes alternately");
        printf("\n 27.Remove duplicates(sorted)");
        printf("\n 28.Remove duplicates(unsorted)");
        printf("\n 29.Alternatively split a list");
        printf("\n 30.Sort 0s,1s,2s");
        printf("\n 31.Sort 0s,1s,2s by changing links");
        printf("\n 32.Sort by actual values(absoulte sorted)");
        printf("\n 33.Insertion sort");
        printf("\n 34.Merge sort");
        printf("\n 35.Quick sort");
        printf("\n 36.Sort a list that is sorted alternating ascending and descending orders");
        printf("\n 37.Get nth node");
        printf("\n 38.Print middle");
        printf("\n 39.Print nth node from end");
        printf("\n 40.Number of times a node has occurred");
        printf("\n 41.Detect a loop(insert 5 nodes)");
        printf("\n 42.Detect and remove loop");
        printf("\n 43.Decimal Equivalent");
        printf("\n 44.Swap nodes without swapping data");
		printf("\n 45.Pairwise Swap");
        printf("\n 46.Pairwise Swap Recursive");
        printf("\n 47.Add one");
        printf("\n 48.Add one Recursive");
        printf("\n 49.ZigZag a < b > c < d > ..");
        printf("\n 50.Rearrange odd and even positioned nodes together");
        printf("\n 51.Move last node to front");
        printf("\n 52.Move middle node to front");
        printf("\n 53.Count Rotations");
		printf("\n 54.Exit");
        printf("\n Enter the choice:");
        scanf("%d", &n);
		switch(n)
		{
			case 1: addatbeg();
					display(start);
					break;
			case 2: addatend(start);
					display(start);
					break;
			case 3: addatmid(start);
					display(start);
					break;
			case 4: sorted_insert(start);
                    display(start);
                    break;
            case 5: scanf("%d", &n);
					insert_middle(head);
            		display(head);
            		break;
			case 6: scanf("%d", &n);
					insert_nth_from_last(head, n);
            		display(head);
            		break;
			case 7: delatbeg();
					display(start);
					break;
			case 8: delatend(start);
					display(start);
					break;
			case 9: delatmid(start);
		         	display(start);
					break;
			case 10: delalt(start);
			         display(start);
			         break;
            case 11: delaltRec(start);
			         display(start);
			         break;
            case 12: deletelist(start);
                     display(start);
                     break;
        	case 13: delNode(start->next->next);
        			 display(start);
        			 break;
        	case 14: printf("\n Enter the position: ");
					 scanf("%d", &position);
					 delposition(start, position);
        			 display(start);
        			 break;
        	case 15: printf("\n Enter the key: ");
					 scanf("%d", &key);
					 delLastOcc(start, key);
        			 display(start);
        			 break;
        	case 16: printf("\n Enter m and n: ");
					 scanf("%d%d", &M, &N);
					 skipMdeleteN(start, M, N);
        			 display(start);
        			 break;
			case 17: printf("\n No. of nodes: %d",count(start));
                     break;
            case 18: printf("\n No. of nodes: %d",countRec(start));
                     break;
            case 19: printf("\n Enter the element to be searched for:");
					 scanf("%d", &x);
					 if(search(start, x))
            			printf("\n Found");
            		 else
            			printf("\n Not found");
            		 break;
            case 20: printf("\n Enter the element to be searched for:");
					 scanf("%d", &x);
					 if(searchRec(start, x))
            			printf("\n Found");
            		 else
            			printf("\n Not found");
            		 break;
            case 21: printf("\n Enter the value to be replaced:");
                     scanf("%d", &oldv);
                     printf("\n Enter the new value:");
                     scanf("%d", &newv);
                     modify(oldv, newv, start);
                     display(start);
                     break;
            case 22: printReverse(start);
            		 break;
            case 23: reverse(start);
                     display(start);
                     break;
            case 24: reverseRec(start);
                     display(start);
                     break;
            case 25: printf("\n Enter the factor: ");
                     scanf("%d", &k);
                     start = revk(start, k);
                     display(start);
              		 break;
            case 26: printf("\n Enter the factor: ");
                     scanf("%d", &kalt);
                     start = revkalt(start, kalt);
                     display(start);
                     break;
            case 27: removedupsort(start);
                     display(start);
                     break;
            case 28: removedupunsort(start);
            		 display(start);
            		 break;
            case 29: splitList(start, &first, &second);
            		 display(first);
            		 printf("\n");
            		 display(second);
            		 break;
            case 30: sort012(start);
                     display(start);
                     break;
            case 32: sort_actual(start);
            		 display(start);
            		 break;
            case 33: insertion_sort(start);
            		 display(start);
            		 break;
            case 36: sortAscendDescendList(start);
            	     display(start);
            	     break;
			case 37: printf("\n Enter the index: ");
                     scanf("%d", &index);
                     printf("\n The node at %d position is %d", index, getnth(start, index));
                     break;
            case 38: printf("\n The middle node is %d", printmid(start));
                     break;
            case 39: printf("\n Enter the nth node: ");
                     scanf("%d", &nend);
                     printf("\n The %dth node from end is %d", nend, printnthfromend(start, nend));
                     break;
            case 40: printf("\n Enter a number: ");
                     scanf("%d", &n1);
                     printf("\n %d has occurred %d times", n1, dupcount(start, n1));
                     break;
            case 41: start->next->next->next->next = start;
                     if(detectloop(start))
                     	printf("Loop is detected");
                     break;
            case 42: start->next->next->next->next = start;
            		 //display(start);
            		 detectandRemoveloop(start);
            		 display(start);
            		 break;
            case 43: printf("%d", decimalValue(start));
            		 break;
            case 44: printf("\n Enter the nodes to be swapped: ");
                     scanf("%d%d", &x, &y);
					 swapNodes(start, x, y);
            		 display(start);
            		 break;
            case 45: pairwiseSwap(start);
            		 display(start);
            		 break;
            case 46: pairwiseSwapRec(start);
            		 display(start);
            		 break;
            case 47: addOne(start);
            		 display(start);
            		 break;
            case 48: addOneRec(start);
            		 display(start);
            		 break;
            case 49: zigZag(start);
            		 display(start);
            		 break;
        	case 50: rearrangeEvenOdd(start);
        			 display(start);
        			 break;
        	case 51: moveLastToFront(&head);
        			 display(head);
        			 break;
        	case 52: moveMiddleToFront(&head);
        			 display(head);
        			 break;
        	case 53: printf("%d",countRotations(head));
        			 break;
			case 54 : goto exit;
        }
	}
	exit:
    return 0;
}                                                                    
                            

