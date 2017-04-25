#include<iostream>
#include<stdio.h>
using namespace std;

struct Point
{
    int x, y;
};

int onSegment(Point p1, Point p2, Point p3)
{
    if(p2.x <= max(p1.x, p3.x) && p2.x >= min(p1.x, p3.x) && p2.y <= max(p1.y, p3.y) && p2.y >= min(p1.y, p3.y))
       return 1;
	else
    	return 0;
}
 
int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if(val == 0) 
		return 0;  
    return (val > 0)? 1: 2; 
}

int doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if(o1 != o2 && o3 != o4)
    	return 1;
    else if(o1 == 0 && onSegment(p1, p2, q1)) 
		return 1;
    else if(o2 == 0 && onSegment(p1, q2, q1)) 
		return 1;
	else if(o3 == 0 && onSegment(p2, p1, q2)) 
		return 1;
	else if (o4 == 0 && onSegment(p2, q1, q2)) 
		return 1;
	else
		return 0; 
}
 
int main()
{
    Point p1 = {1, 1}, q1 = {10, 1};
    Point p2 = {1, 2}, q2 = {10, 2};
 
    if(doIntersect(p1, q1, p2, q2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

