// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/compiler-version-2/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

string process(string str)
{
    int n = str.length();
    int ignore = 0;
    string output;
    for(int i = 0; i < n; i++)
    {
        if(i + 1 < n && str[i] == '/' && str[i + 1] == '/')
            ignore = 1;
        if(i + 1 < n && str[i] == '-' && str[i + 1] == '>' && ignore == 0)
        {
            output += '.';
            i++;
        }
        else
            output += str[i];
    }
    return output;
}

int main()
{
    string str;
    while(getline(cin, str))
    {
        cout << process(str) << endl;
    }
    return 0;
}
