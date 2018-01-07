#include<iostream>
#include<stdio.h>
using namespace std;
 
struct Point
{
	int x, y;
};

float area(Point p1, Point p2, Point p3)
{
	return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) )/2);
}
 
int isInside(Point p1, Point p2, Point p3, Point x)
{   
	float A = area(p1, p2, p3);
	float A1 = area(x, p1, p2);
	float A2 = area(x, p2, p3);
	float A3 = area(x, p1, p3);
	return (A == A1 + A2 + A3);
}
 
int main()
{
	Point p1 = {0, 0}, p2 = {20, 0}, p3 = {10, 30}, x = {10, 15};
	if(isInside(p1, p2, p3, x))
		printf ("Inside");
	else
    	printf ("Not Inside");
	return 0;
}
