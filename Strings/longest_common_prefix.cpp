#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

string lcp(string s[], int n)
{

	sort(s, s + n);
	
	string first = s[0];
	string last = s[n-1];
	
	int i;
	for(i = 0; first[i]; i++)
	{
		if(first[i] != last[i])
			break;
	}
	
	return first.substr(0, i);
}

int main()
{
    string a[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
    int n = 4;
    string prefix = lcp(a, n);
    if(prefix.length())
        cout << prefix;
    else
        printf("There is no common prefix");
    return 0;
}

