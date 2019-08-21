// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/frequency-of-students/

#include<map>
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;

void frequency(vector<string> a, int n)
{
    map<string, int> hash;
    for(int i = 0; i < n; i++)
        hash[a[i]]++;
        
    for(auto it = hash.begin(); it != hash.end(); it++)
        cout << it->first << " " << it->second << endl;
}

int main()
{
    int n;
    scanf("%d", &n);
    string str;
    vector<string> a;
    for(int i = 0; i < n; i++) 
	{
        cin >> str;
        a.push_back(str);
    }
        
    frequency(a, n);
    
    return 0;
}
