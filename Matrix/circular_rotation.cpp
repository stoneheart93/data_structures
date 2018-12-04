#include<iostream>
#include<string>
using namespace std;

int isPermutedMatrix(int M[10][10], int n)
{
    string str_cat = "";
    for(int j = 0 ; j < n ; j++)
    	str_cat += to_string(M[0][j]);
 
    str_cat = str_cat + str_cat;
 
    for(int i = 1; i < n; i++)
    {
		string curr_str = "";
        for(int j = 0 ; j < n; j++)
        	curr_str += to_string(M[i][j]);
 		
		if(str_cat.find(curr_str) == string::npos)
        	return 0;
    }
 
    return 1;
}

int main() 
{
	int i, j, n;
	int M[10][10];
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			scanf("%d", &M[i][j]);
		}
	}
	printf("%d", isPermutedMatrix(M, n));
	return 0;
}

