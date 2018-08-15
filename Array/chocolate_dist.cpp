/*
Given an array of n integers where each value represents number of chocolates in a packet. Each packet can have variable number 
of chocolates. There are m students, the task is to distribute chocolate packets such that:
1) Each student gets one packet.
2) The difference between the number of chocolates in packet with maximum chocolates and packet with minimum chocolates given to the 
students is minimum.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int findMinDiff(int a[], int n, int m)
{
    if(n < m)
    	return -1;

	if(m == 0)
    	return 0;

	sort(a, a + n);
 
    int min_diff = INT_MAX;
 
    for(int i = 0; i + m - 1 < n; i++)
    {
        int diff = a[i + m - 1] - a[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main() 
{
    int n, i, m;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	printf("%d", findMinDiff(a, n, m));
	return 0;
}
