#include<iostream>
#include<stack>
using namespace std;

void antispiralPrint(int M[10][10], int m, int n)
{
	stack<int> s;
	int i, k = 0, l = 0;
    while(k < m && l < n)
    {
        for(i = l; i < n; i++)
            s.push(M[k][i]);
        k++;
 
        for(i = k; i < m; i++)
            s.push(M[i][n-1]);
        n--;
 
        if(k < m)
        {
            for(i = n - 1; i >= l; i--)
            	s.push(M[m-1][i]);
            m--;
        }
 
        if(l < n)
        {
            for(i = m - 1; i >= k; i--)
                s.push(M[i][l]);
            l++;    
        }        
    }
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
}

int main() 
{
	int i, j, m, n;
	int M[10][10];
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	antispiralPrint(M, m, n);
	return 0;
}

/*
ip
3 3
1 2 3
4 5 6
7 8 9
op
5 4 7 8 9 6 3 2 1
*/
