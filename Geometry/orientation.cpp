#include<iostream>
#include<stdio.h>
using namespace std;
 
struct Point
{
	int x, y;
};

void orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if(val == 0) 
		printf("Collinear");
	else if(val < 0)
		printf("Counterclockwise");
	else
		printf("Clockwise"); 
}

int main()
{
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
	orientation(p1, p2, p3);
    return 0;
}

