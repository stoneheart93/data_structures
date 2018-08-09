#include<stdio.h>
#include<math.h>

struct Point
{
	int x, y;
};

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
int latticePoints(Point p, Point q)
{
	// || to x axis
	if(p.y == q.y)
		return abs(p.x - q.x) - 1;
	// || to y axis
	else if(p.x == q.x)
		return abs(p.y - q.y) - 1;
	else
		return gcd(abs(q.x - p.x), abs(q.y - p.y)) - 1;
}

int main()
{
	Point p = {1, 9}, q = {8, 16};
	printf("%d", latticePoints(p, q));
	return 0;
}
