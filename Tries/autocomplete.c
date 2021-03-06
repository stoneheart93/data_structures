#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
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

char* append(char* str, char ch)
{
	char* result = (char*)malloc(sizeof(char) * (strlen(str) + 2));
	int i, j = 0;
	for(i = 0; str[i]; i++)
		result[j++] = str[i];
	result[j++] = ch;
	result[j] = '\0';
	return result;
}

void autocompleteUtil(struct trienode* root, char* prefix)
{
	if(root == NULL)
		return;
		
	if(root->isEnd == true)
		printf("%s\n", prefix);
		
	int i;
	for(i = 0; i < ALPHABET; i++)
	{
		if(root->children[i] != NULL)
			autocompleteUtil(root->children[i], append(prefix, i + 'a'));	
	}
}

void autocomplete(struct trienode* root, char* prefix)
{
	struct trienode* rider = root;
	int i;
	for(i = 0; prefix[i]; i++)
	{
		int index = prefix[i] - 'a';
		if(rider->children[index] == NULL)
			return;
		rider = rider->children[index];
	}
	autocompleteUtil(rider, prefix);
}

int main()
{
	char* keys[] = {"hello", "dog", "hell", "cat", "a", "hel", "help", "helps", "helping"};
	int n = 9;
	
	struct trienode* root = getNode();
	
	int i;
	for(i = 0; i < n; i++)
		insert(root, keys[i]);
		
	autocomplete(root, "hel");
	return 0;
}
