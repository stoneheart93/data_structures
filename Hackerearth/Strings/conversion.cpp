// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/conversion-11/description/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
 
string convert(string str)
{
    string output;
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
            output += '$';
        else if(str[i] >= 'A' && str[i] <= 'Z')
            output += to_string(str[i] - 'A' + 1);
        else
            output += to_string(str[i] - 'a' + 1);
    }
    return output;
}
 
int main()
{
    int tc;
    string str;
    scanf("%d\n", &tc);
    while(tc--)
    {
        getline(std::cin, str);
        cout << convert(str) << endl;
    }
    return 0;
}
