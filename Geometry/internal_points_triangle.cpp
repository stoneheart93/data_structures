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

float area(Point p1, Point p2, Point p3)
{
	return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) )/2);
}
 
int internal_points(Point p1, Point p2, Point p3)
{
	// A = I + B/2 - 1
	// I = A + 1 - B/2
	
	float A = area(p1, p2, p3);
	
	int B = latticePoints(p1, p2) + latticePoints(p2, p3) + latticePoints(p1, p3) + 3;  	

	return (A + 1 - B/2);
}

int main()
{
	Point p1 = {0, 0}, p2 = {5, 0}, p3 = {0, 5};
	printf("%d", internal_points(p1, p2, p3));
	return 0;
}
