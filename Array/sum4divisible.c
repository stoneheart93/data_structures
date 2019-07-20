/*
There are only three condition that can arise whose sum is divisible by 4
1) If both are divisible by 4.
2) If one of them is equal to 1 modulo 4 and other is 3 modulo 4. 
3) If both of them is equal to 2 modulo 4

freq0 C 2 + freq2 C 2 + (freq1 . freq3)

*/

#include<stdio.h>

int sum4Divisible(int a[], int n)
{
	int i, ans = 0;
	
    int freq[4] = {0, 0, 0, 0};
    for(i = 0; i < n; i++)
		freq[a[i] % 4]++;
 
    ans += freq[0] * (freq[0] - 1) / 2; 
    ans += freq[2] * (freq[2] - 1) / 2;
    ans += freq[1] * freq[3];
 
    return ans;
}
 
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", sum4Divisible(a, n));
	return 0;
}

/*
ip
5
2 2 1 7 5
op
3
*/
