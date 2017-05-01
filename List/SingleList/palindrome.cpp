#include<iostream>
#include<string>
using namespace std;
#include<stdlib.h>

struct node
{
    string data;
    struct node *next;
};
 
struct node* newNode(const char* str)
{
	struct node *temp = new struct node;
	temp->data = str;
	temp->next = NULL;
	return temp;
}
 
void display(struct node* rider)
{
	while(rider != NULL)
	{
	    cout << "--->" << rider->data;
	    rider = rider->next;
    }     
}

int isPalindromeUtil(string str)
{
    int l = 0;
    int h = str.length() - 1;
 	
	while (h > l)
    {
        if (str[l++] != str[h--])
            return 0;
    }
    return 1;
}

int isPalindrome(struct node *rider)
{
    string str = "";
    while(rider != NULL)
    {
        str.append(rider->data);
        rider = rider->next;
    }
 	return isPalindromeUtil(str);

}
int main()
{
    struct node *start = newNode("a");
    start->next = newNode("bc");
    start->next->next = newNode("d");
    start->next->next->next = newNode("dcb");
    start->next->next->next->next = newNode("a");
    display(start);
    if(isPalindrome(start)) 
		cout << "\n true";
	else
        cout << "\n false";
    return 0;
}
