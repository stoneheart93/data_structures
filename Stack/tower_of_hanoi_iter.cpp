#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

void moveDisksBetweenTwoPoles(stack<int>& src, stack<int>& dest, char s, char d)
{
    if(src.empty())
    {
    	int pole2TopDisk = dest.top();
		dest.pop(); 
 
    	src.push(pole2TopDisk);
    	return;
    }
    else if(dest.empty())
    {
    	int pole1TopDisk = src.top();
    	src.pop();
    
        dest.push(pole1TopDisk);
    	printf("\nMove disk %d from rod %c to rod %c", pole1TopDisk, s, d);
    	return;
    }
    
    int pole1TopDisk = src.top();
    src.pop();
	int pole2TopDisk = dest.top();
	dest.pop(); 
 
    if(pole1TopDisk > pole2TopDisk)
    {
        src.push(pole1TopDisk);
        src.push(pole2TopDisk);
    	printf("\nMove disk %d from rod %c to rod %c", pole2TopDisk, d, s);
    }
    else
    {
		dest.push(pole2TopDisk);
        dest.push(pole1TopDisk);
		printf("\nMove disk %d from rod %c to rod %c", pole1TopDisk, s, d);
    }
}

void towerOfHanoi(int n, stack<int>& src, stack<int>& aux, stack<int>& dest)
{
    int i, moves;
    char from_rod = 'A', aux_rod = 'B', to_rod = 'C';
    
	if(n % 2 == 0)
    {
        char temp = aux_rod;
        aux_rod = to_rod;
        to_rod = temp;
    }
    
	moves = pow(2, n) - 1;
 
	for(int i = n; i >= 1; i--)
    	src.push(i);
 
 	for(int i = 1; i <= moves; i++)
    {
        if(i % 3 == 1)
        	moveDisksBetweenTwoPoles(src, dest, from_rod, to_rod);
        else if(i % 3 == 2)
        	moveDisksBetweenTwoPoles(src, aux, from_rod, aux_rod); 
        else if(i % 3 == 0)
        	moveDisksBetweenTwoPoles(aux, dest, aux_rod, to_rod);
    }
}
 
int main()
{
	int n;
	scanf("%d", &n);	
	stack<int> src, dest, aux;
	towerOfHanoi(n, src, aux, dest);  
    return 0;
}
