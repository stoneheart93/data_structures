#include<iostream>
#include<list>
using namespace std;

void BFS(int x, int num)
{
	list<int> queue;
	queue.push_back(num);

	while(!queue.empty())
	{
		int num = queue.front();
		queue.pop_front();
		
		if(num <= x)
		{
			printf("%d ", num);
			int last_dig = num % 10;
 
            if(last_dig == 0)
                queue.push_back((num * 10) + (last_dig + 1));
			else if (last_dig == 9)
                queue.push_back((num * 10) + (last_dig - 1));
            else
            {
                queue.push_back((num * 10) + (last_dig - 1));
                queue.push_back((num * 10) + (last_dig + 1));
            }
        }
    }
}

void printJumping(int x)
{
    printf("0 ");
	int i;
	for(i = 1; i <= 9 && i <= x; i++)
    	BFS(x, i);
}
 
int main()
{
    int x;
	scanf("%d", &x);
    printJumping(x);
    return 0;
}

/* 
ip 
40
op
0 1 10 12 2 21 23 3 32 34 4 5 6 7 8 9 
*/
