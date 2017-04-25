#include<iostream>
#include<stdio.h>
using namespace std;
 
struct Point
{
	int x, y;
};
 
int distSq(Point p, Point q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}
 
int isSquare(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = distSq(p1, p2);  
    int d2 = distSq(p1, p3);  
    int d3 = distSq(p1, p4);  
	
	if(d1 == d2 && 2 * d1 == d3)
    {
        int d4 = distSq(p2, p4);
		int d5 = distSq(p3, p4);
        return (d4 == d5 && d4 == d1);
    }
    else if(d2 == d3 && 2 * d2 == d1)
    {
        int d4 = distSq(p2, p3);
        int d5 = distSq(p2, p4);
        return (d4 == d5 && d4 == d2);
    }
    else if (d1 == d3 && 2 * d1 == d2)
    {
        int d4 = distSq(p2, p3);
        int d5 = distSq(p3, p4);
        return (d4 == d5 && d4 == d1);
    }
 	else 
    	return 0;
}
 
int main()
{
    Point p1 = {20, 10}, p2 = {10, 20}, p3 = {20, 20}, p4 = {10, 10};
    if(isSquare(p1, p2, p3, p4))
		printf("Yes");
	else
		printf("No");
    return 0;
}
