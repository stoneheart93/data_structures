#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

void sorted_insert(struct node *rider)
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

void modify(int old_value, int new_value, struct node* rider)
{
    while(rider->data != old_value && rider != NULL)
        rider=rider->next;
    if(rider==NULL)
        printf("The inputted value not found in the list");
    else
        rider->data = new_value;      
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

void recrev(struct node* first)
{
    if(first == NULL|| first->next == NULL)
        return;
    rest = first->next;
    recrev(rest);
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


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void pairwiseSwap(struct node* rider)
{
	if(rider != NULL && rider->next != NULL)
  	{
    	swap(&rider->data, &rider->next->data);
    	pairwiseSwap(rider->next->next);
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
void insertion_sort(struct node *rider)
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

int addWithCarry(struct node *rider)
{
    if(rider == NULL)
    	return 1;
 
    int res = rider->data + addWithCarry(rider->next);

    rider->data = res % 10;
    return (res / 10);
} 
void addOne(struct node *rider)
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
 
int main()
{
    int n, oldv, newv, index, nend, n1, k, kalt;
    struct node* res;
	struct node* res1;
    
	struct node* i = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data: ");
    scanf("%d", &i->data);
    i->next = NULL;
    start = i;
    
	while(1)
	{
		printf("\n\n LIST OF OPERATIONS");
		printf("\n 1.Insertion at the front");
        printf("\n 2.Insertion at the end");
        printf("\n 3.Insertion in the middle");
        printf("\n 4.Insertion in a sorted way");
        printf("\n 5.Deletion at the front");
        printf("\n 6.Deletion at the end");
        printf("\n 7.Deletion in the middle");
        printf("\n 8.Deletion of alternate nodes");
        printf("\n 9.Delete entire list");
        printf("\n 10.Delete given pointer to a node");
        printf("\n 11.Count");
        printf("\n 12.Modify");
        printf("\n 13.Reverse");
        printf("\n 14.Reverse Recursion");
        printf("\n 15.Reverse by k nodes");
        printf("\n 16.Reverse by k nodes alternately");
        printf("\n 17.Remove duplicates(sorted)");
        printf("\n 18.Sort 0s,1s,2s");
        printf("\n 19.Sort by actual values(absoulte sorted)");
        printf("\n 20.Insertion sort");
        printf("\n 21.Get nth node");
        printf("\n 22.Print middle");
        printf("\n 23.Print nth node from end");
        printf("\n 24.Number of times a node has occurred");
        printf("\n 25.Detect a loop(insert 5 nodes)");
        printf("\n 26.Detect and remove loop");
        printf("\n 27.Decimal Equivalent");
        printf("\n 28.Pairwise Swap");
        printf("\n 29.Add one");
        printf("\n 30.ZigZag a < b > c < d > ..");
        printf("\n 31.Rearrange odd and even positioned nodes together");
		printf("\n 32.Exit");
        printf("\n Enter the choice:");
        scanf("%d",&n);
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
			case 5: delatbeg(start);
					display(start);
					break;
			case 6: delatend(start);
					display(start);
					break;
			case 7: delatmid(start);
		         	display(start);
					break;
			case 8: delalt(start);
			        display(start);
			        break;
            case 9: deletelist(start);
                    display(start);
                    break;
        	case 10 : delNode(start->next->next);
        			  display(start);
        			  break;
			case 11: printf("\n No. of nodes: %d",count(start));
                     break;
            case 12: printf("\n Enter the value to be replaced:");
                     scanf("%d", &oldv);
                     printf("\n Enter the new value:");
                     scanf("%d", &newv);
                     modify(oldv, newv, start);
                     display(start);
                     break;
            case 13: reverse(start);
                     display(start);
                     break;
            case 14: recrev(start);
                     display(start);
                     break;
            case 15: printf("\n Enter the factor");
                     scanf("%d", &k);
                     res = revk(start, k);
                     display(res);
              		 break;
            case 16: printf("\n Enter the factor");
                     scanf("%d", &kalt);
                     res1 = revkalt(start, kalt);
                     display(res1);
                     break;
            case 17: removedupsort(start);
                     display(start);
                     break;
            case 18: sort012(start);
                     display(start);
                     break;
            case 19: sort_actual(start);
            		 display(start);
            		 break;
            case 20: insertion_sort(start);
            		 display(start);
            		 break;
			case 21: printf("\n Enter the index: ");
                     scanf("%d", &index);
                     printf("\n The node at %d position is %d", index, getnth(start, index));
                     break;
            case 22: printf("\n The middle node is %d", printmid(start));
                     break;
            case 23: printf("\n Enter the nth node: ");
                     scanf("%d", &nend);
                     printf("\n The %dth node from end is %d", nend, printnthfromend(start, nend));
                     break;
            case 24: printf("\n Enter a number: ");
                     scanf("%d", &n1);
                     printf("\n %d has occurred %d times", n1, dupcount(start, n1));
                     break;
            case 25: start->next->next->next->next = start;
                     if(detectloop(start))
                     	printf("Loop is detected");
                     break;
            case 26: start->next->next->next->next = start;
            		 //display(start);
            		 detectandRemoveloop(start);
            		 display(start);
            		 break;
            case 27: printf("%d", decimalValue(start));
            		 break;
            case 28: pairwiseSwap(start);
            		 display(start);
            		 break;
            case 29: addOne(start);
            		 display(start);
            		 break;
            case 30: zigZag(start);
            		 display(start);
            		 break;
        	case 31: rearrangeEvenOdd(start);
        			 display(start);
        			 break;
			case 32: goto exit;
        }
	}
	exit:
    return 0;
}
                 
                                                            

             
        

                     

             

