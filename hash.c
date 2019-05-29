#include<stdio.h>

struct node
{
	char english[100];
	char french[100];
	struct node* next;
};

unsigned long compute_hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;N

    while (c = *str++)
    	hash = (hash % 1000 + c % 1000) % 1000; /* hash * 33 + c */

    return hash % 1000;
}

struct node* hash[1000];

void addToHash(char str1[], char str2[])
{
	int index = compute_hash(str1);
	
	struct node* temp = (struct node*) malloc(sizeof(struct node));	
	strcpy(temp->english, str1);
	strcpy(temp->french, str2);
	
	
	temp->next = hash[index]; //for handling collision
	hash[index] = temp;
}

void hashLookUp(char str3[])
{
	int index = compute_hash(str3);
	if(hash[index] != 0)
	{
		struct node* rider = hash[index];
		while(rider != NULL)
		{
			printf("%s", rider->french);
			rider = rider->next;
		}
	}
}

int main()
{
	int n, q;
	char str1[100], str2[100], str3[100];
	int key, value;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s%s", str1, str2);
		//scanf("%d%d", &key, &value);
		//addToHash(key, value);
		addToHash(str1, str2);
	}
	scanf("%d", &q);
	while(q--)
	{
		scanf("%s", str3);
		hashLookUp(str3);
	}
	return 0;
}
