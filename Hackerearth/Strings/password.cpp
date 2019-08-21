// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/password-1/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

void findPassword(vector<string> a)
{
    unordered_set<string> hash;
    for(int i = 0; i < a.size(); i++)
        hash.insert(a[i]);
        
    for(int i = 0; i < a.size(); i++)
    {
        string rev = a[i];
        reverse(rev.begin(), rev.end());
        if(hash.find(rev) != hash.end())
        {
            cout << rev.length() << " " << a[i][rev.length() / 2] << endl;
            break;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<string> a;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        a.push_back(str);
    }
    
    findPassword(a);
    return 0;
}
