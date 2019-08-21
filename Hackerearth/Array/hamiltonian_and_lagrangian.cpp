// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/hamiltonian-and-lagrangian/

#include<vector>
#include<stdio.h>
using namespace std;

void notSmaller(int a[], int n)
{
    vector<int> maxA;
    int maxFromRight = a[n - 1];
    maxA.push_back(maxFromRight);
    
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] >= maxFromRight)
        {
            maxFromRight = a[i];
            maxA.push_back(maxFromRight);
        }
    }
    
    for(int i = maxA.size() - 1; i >= 0; i--)
        printf("%d ", maxA[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int* a = new int[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    notSmaller(a, n);
    
    delete[] a;
}
