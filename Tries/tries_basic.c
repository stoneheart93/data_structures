#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define ALPHABET 26

struct trienode
{
	struct trienode* children[ALPHABET];
	bool isEnd;
};

struct trienode* getNode()
{
	struct trienode* newnode = (struct trienode*)malloc(sizeof(struct trienode));
	int i;
	for(i = 0; i < ALPHABET; i++)
		newnode->children[i] = NULL;
	newnode->isEnd = false;
	return newnode;	
}

void insert(struct trienode* root, char* key)
{
	struct trienode* rider = root;
	int i;
	for(i = 0; key[i]; i++)
	{
		int index = key[i] - 'a';
		if(rider->children[index] == NULL)
			rider->children[index] = getNode();
		rider = rider->children[index];
	}
	rider->isEnd = true;
}

bool search(struct trienode* root, char* key)
{
	struct trienode* rider = root;
	int i;
	for(i = 0; key[i]; i++)
	{
		int index = key[i] - 'a';
		if(rider->children[index] == NULL)
			return false;
		rider = rider->children[index];
	}
	return (rider->isEnd == true);
}

int size(struct trienode* root)
{
	if(root == NULL)
		return 0;
	int i;
	int count = 1;
	for(i = 0; i < ALPHABET; i++)
	{
		if(root->children[i] != NULL)
			count += size(root->children[i]);	
	}
	return count;
}

int main()
{
	int choice;
	struct trienode* root = getNode();
	char key[100];
	
	while(1)
	{
		printf("\nOperations");
		printf("\n1.Insert");
		printf("\n2.Search");
		printf("\n3.No of nodes");
		printf("\n5.Exit");
		scanf("\n%d", &choice);
		switch(choice)
		{
			case 1: scanf("%s", key);
					insert(root, key);
					break;
			case 2: scanf("%s", key);
					if(search(root, key))
						printf("Found");
					else
						printf("Not found");
					break;
			case 3: printf("%d", size(root));
					break;
			case 5: goto exit;
		}
	}
	exit:
	return 0;
}
