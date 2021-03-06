#include<iostream>
#include<vector>
using namespace std;
 
int nextSparse(int x)
{
    vector<bool> bin;
    while (x != 0)
    {
        bin.push_back(x & 1);
        x >>= 1;
    }
    bin.push_back(0);
    int n = bin.size();  
	
	int last_final = 0;
 
    for (int i = 1; i < n - 1; i++)
    {
       if (bin[i] == 1 && bin[i - 1] == 1 && bin[i + 1] != 1)
       {
            bin[i + 1] = 1;
            for (int j = i; j >= last_final; j--)
                bin[j] = 0;
 			last_final = i + 1;
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += bin[i] * (1 << i);
    return ans;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", nextSparse(x));
    return 0;
}

