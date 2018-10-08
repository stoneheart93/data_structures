#include<iostream>
#include<string>
using namespace std;

int countSubstrings(string str) 
{ 
   int n = str.length(); 
   return n*(n+1)/2; 
} 
  
int main() 
{ 
    string s;
	cin >> s; 
    printf("%d", countSubstrings(s));
    return 0;
}

