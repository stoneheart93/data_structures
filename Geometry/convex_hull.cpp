#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
 
struct Point
{
	int x, y;
};

Point p0;
 
Point nextToTop(stack<Point> &s)
{
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}
 
void swap(Point* a, Point* b)
{
    Point temp = *a;
    *a = *b;
    *b = temp;
}
 
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
 
int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if(val == 0) 
		return 0;  
    return (val > 0)? 1: 2; 
}
 
int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;
	int o = orientation(p0, *p1, *p2);
	if(o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
	return (o == 2)? -1: 1;
}
 
void convexHull(Point points[], int n)
{
	int ymin = points[0].y, min = 0;
	for(int i = 1; i < n; i++)
	{	
		if((points[i].y < ymin) || (points[i].y == ymin && points[i].x < points[min].x))
        {
        	ymin = points[i].y;
			min = i;	
		}
	}
 
   swap(&points[0], &points[min]);
 
	p0 = points[0];
	qsort(&points[1], n-1, sizeof(Point), compare);
 
	int m = 1; 
	for(int i = 1; i < n; i++)
	{
		while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
        	i++;
 
		points[m] = points[i];
		m++;  
	}
 
 	if(m < 3) 
	 	return;
 
	stack<Point> s;
	s.push(points[0]);
	s.push(points[1]);
	s.push(points[2]);
 
	for(int i = 3; i < m; i++)
	{
		while(orientation(nextToTop(s), s.top(), points[i]) != 2)
        	s.pop();
    	s.push(points[i]);
	}
 
	while (!s.empty())
   	{
		Point p = s.top();
    	printf("(%d, %d)\n", p.x, p.y);       
		s.pop();
   	}
}
 
int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = 8;
    convexHull(points, n);
    return 0;
}

