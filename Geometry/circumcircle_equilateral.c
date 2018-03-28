#include<stdio.h>
#define PI 3.14159265
 
float area_circumscribed(float a)
{
    return (a * a * (PI / 3));
}
 
int main()
{
    float a;
	scanf("%f", &a);
	printf("Area : %.2f ", area_circumscribed(a));
    return 0;
}
