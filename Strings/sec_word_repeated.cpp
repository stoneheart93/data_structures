#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

string secRepeated(vector<string> words)
{
	unordered_map<string, int> occ;
	for(int i = 0; i < words.size(); i++)
		occ[words[i]]++;
		
	int first_max = 0, sec_max = 0;
	for(auto it = occ.begin(); it != occ.end(); it++)
	{
		if(it->second > first_max)
		{
			sec_max = first_max;	
			first_max = it->second;
		}
		else if(it->second > sec_max && it->second != first_max)
			sec_max = it->second;
	}
	for(auto it = occ.begin(); it != occ.end(); it++)
	{
		if(it->second == sec_max)
			return it-> first;
	}	
}
int main()
{
    vector<string> seq = { "ccc", "aaa", "ccc", "ddd", "aaa", "aaa" };
    cout << secRepeated(seq);
    return 0;
}
