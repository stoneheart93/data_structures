#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<conio.h> 
struct IndexNode
{
    int index;
    struct IndexNode* next;
};
 
struct TrieNode
{
    int isEnd;  
    struct TrieNode *children[26]; 
    struct IndexNode *list; 
};

struct TrieNode* newTrieNode()
{
    struct TrieNode* temp = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    temp->isEnd = 0;
    for (int i = 0; i<26; i++)
        temp->children[i] = NULL;
    temp->list=NULL;
    return temp;
}
 
struct IndexNode* newIndexNode(int index)
{
    struct IndexNode* temp = (struct IndexNode*)malloc(sizeof(struct IndexNode));
    temp->index = index;
    temp->next = NULL;
    return temp;
}

int compare(const void* a, const void* b)
{
    return *(char*)a - *(char*)b; 
}
 
void insert(struct TrieNode *crawl, char *str,int Index)
{
	int i, index;
	int len = strlen(str);
	for(i = 0; i < len; i++)
    {
          index = str[i]-'a';
     //     printf("%d",index);
          if(!crawl->children[index])
          {
                                     crawl->children[index]=newTrieNode();
          }
          crawl=crawl->children[index];
    }
    //printf("add");
    crawl->isEnd=1;
    if(!crawl->list)
    {
                    crawl->list=newIndexNode(Index);
    }
    else
    {
        struct IndexNode *rider = crawl->list;
        while(rider->next!=NULL)
              rider=rider->next;
        rider->next=newIndexNode(Index);
    }
  //  printf("end");
}
// This function traverses the built trie. When a leaf node is reached,
// all words connected at that leaf node are anagrams. So it traverses
// the list at leaf node and uses stored index to print original words
void printAnagramsUtil(struct TrieNode* root, char *wordArr[])
{
    if (root == NULL)
        return;
 
    // If a lead node is reached, print all anagrams using the indexes
    // stored in index linked list
    if (root->isEnd)
    {
        // traverse the list
        IndexNode* pCrawl = root->list;
        while (pCrawl != NULL)
        {
            printf( "%s \n", wordArr[ pCrawl->index ] );
            pCrawl = pCrawl->next;
        }
    }
 
    for (int i = 0; i < 26; ++i)
        printAnagramsUtil(root->children[i], wordArr);
}
 
// The main function that prints all anagrams together. wordArr[] is input
// sequence of words.
void printAnagramsTogether(char* wordArr[], int size)
{
    // Create an empty Trie
    struct TrieNode* root = newTrieNode();
 
    // Iterate through all input words
    for (int i = 0; i < size; ++i)
    {
        // Create a buffer for this word and copy the word to buffer
        int len = strlen(wordArr[i]);
        char *buffer = new char[len+1];
        strcpy(buffer, wordArr[i]);
 
        // Sort the buffer
        qsort( (void*)buffer, strlen(buffer), sizeof(char), compare );
 
        // Insert the sorted buffer and its original index to Trie
        
        insert(root,  buffer, i);
    }
 
    // Traverse the built Trie and print all anagrms together
    printAnagramsUtil(root, wordArr);
}
 
 
// Driver program to test above functions
int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    getch();
    return 0;
}
