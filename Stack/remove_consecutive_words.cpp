#include<string>
#include<stack>
#include<vector>
using namespace std;

int removeConsecutiveSize(vector<string> v)
{
	stack<string> s;
	
	for(int i = 0; i < v.size(); i++)
	{
		if(s.empty())
			s.push(v[i]);
		else
		{
			if(v[i].compare(s.top()) == 0)
				s.pop();
			else
				s.push(v[i]);
		}
	}
	return s.size();
}

int main()
{
	vector<string> v = {"ab", "aa", "aa", "bcd", "ab"}; 
	printf("%d", removeConsecutiveSize(v)); 
    return 0;
}
