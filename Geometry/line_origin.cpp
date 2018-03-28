#include<iostream>
using namespace std;
 
bool checkOrigin(int x1, int y1, int x2, int y2)
{
	return (x1 * (y2 - y1) == y1 * (x2 - x1));
}

int main()
{
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if(checkOrigin(x1, y1, x2, y2))
    	printf("yes");
    else
    	printf("no");
    return 0;
}
