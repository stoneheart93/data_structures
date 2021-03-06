#include<stdio.h>
#include<stack>
using namespace std;

void printNGE(int a[], int n)
{
	int element, next;
	stack<int> s;
	s.push(a[0]);
	
	for(int i = 1; i < n; i++)
    {
        next = a[i];
        while(!s.empty() && next > s.top())
        {
            element = s.top();
            s.pop();
            printf("\n %d --> %d", element, next);
        }
        s.push(next);
    }
    while(!s.empty())
    {
        element = s.top();
        s.pop();
        next = -1;
        printf("\n %d -- %d", element, next);
    }
}

int main()
{
	int n;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printNGE(a, n);
	return 0;
}
