#include<iostream>
#include<unordered_map>
using namespace std;

void printDuplicates(int a[], int n)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++)
        hash[a[i]]++;
 
 
 	bool dup = false;
    for(auto it = hash.begin(); it != hash.end(); it++)
	{
	    if(it->second > 1)
        {
            printf("%d ", it->first);
            dup = true;
        }
    }
 
    if(dup == false)
    	printf("-1");
}

int main()
{
    int n;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printDuplicates(a, n);
    return 0;    
}     

 
