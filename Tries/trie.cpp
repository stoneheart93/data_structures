#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
	int end_string;
	struct node *children[26];
};


struct node* getNode()
{
    struct node * new_node = (struct node*)malloc(sizeof(struct node));
    int i;
    new_node->end_string=0;
    for(i = 0; i < 26; i++)
    {
          new_node->children[i] = NULL;
    }
    return new_node;
}

void insert(struct node *crawl, char *str)
{
	int i, index;
	int len = strlen(str);
	for(i = 0; i < len; i++)
    {
          index = str[i]-'a';
          if(!crawl->children[index])
          {
                                     crawl->children[index]=getNode();
          }
          crawl=crawl->children[index];
    }
    crawl->end_string=1;
}

int check(struct node *crawl, char *str)
{
	int i,index;
	int len=strlen(str);
	for(i = 0;i < len; i++)
    {
          index=str[i]-'a';
          if(!crawl->children[index])
            return 0;
          crawl=crawl->children[index];
	}
	return(crawl!=0 && crawl->end_string);
}

int isLeafNode(struct node *crawl)
{
    return (crawl->end_string);
}
int isFreeNode(struct node *crawl)
{
    int i;
    for(i=0;i<26;i++)
    {
                     if(crawl->children[i])
                                           return 0;
    }
    return 1;
}

int deleteUtil(struct node *crawl,char *str,int level,int len)
{
    if(crawl)
    {
             if(level==len)
             {
                  if(crawl->end_string)
                  {
                                       crawl->end_string=0;
                                       if(isFreeNode(crawl))
                                                            return 1;
                                       else
                                           return 0;
                  }       
             }
             else
             {
                 int index=str[level]-'a';
                 if(deleteUtil(crawl->children[index],str,level+1,len))
                 {
                                                                free(crawl->children[index]);
                                                                crawl->children[index]=NULL;
                                                                return (!isLeafNode(crawl) && isFreeNode(crawl));
                 }
             }
    }
    return 0;
}

void Delete(struct node *crawl,char *str)
{
     int len=strlen(str);
     deleteUtil(crawl,str,0,len);
}

int main()
{
	int n, m, i;
    //n = number of string's to be inserted in trie tree
    //m = number of string's to be checked in trie tree

    
	struct node *root=getNode();
	
	cin >> n;
	while(n--)
    {
		char *str;
		cin >> str;
		insert(root,str); //to insert the string in the trie tree
	}

	cin >> m; //number of string's to be checked
	while(m--)
    {
		char *str;
		cin >> str;
		if(check(root,str)) 
                            cout << "present\n";
		else 
             cout << "not present\n";
	}
	char *str;
	cin >> str;
	Delete(root,str);
	if(check(root,str)) 
                        cout << "present\n";
	else 
         cout << "not present\n";
	
	
	getch();
	return 0;
}
