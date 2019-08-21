// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/

#include<unordered_set>
using namespace std;

bool pairSum(int a[], int n, int k)
{
    unordered_set<int> hash;
    
    for(int i = 0; i < n; i++)
    {
        if(hash.find(k - a[i]) != hash.end())
            return true;
        hash.insert(a[i]);
    }
    return false;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int* a = new int[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    if(pairSum(a, n, k))
        printf("YES\n");
    else
        printf("NO\n");
      
	delete[] a;
	  
    return 0;
}
