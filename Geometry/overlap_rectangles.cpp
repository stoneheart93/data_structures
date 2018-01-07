#include<iostream>
#include<stdio.h>
using namespace std;

struct Point
{
    int x, y;
};
 
int doOverlap(Point l1, Point r1, Point l2, Point r2)
{
	if(l1.x > r2.x || l2.x > r1.x)
		return 0;
    if(l1.y < r2.y || l2.y < r1.y)
		return 0;
	return 1;
}
 
int main()
{
    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};
    if (doOverlap(l1, r1, l2, r2))
        printf("Rectangles Overlap");
    else
        printf("Rectangles Don't Overlap");
    return 0;
}
